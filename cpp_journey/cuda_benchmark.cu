#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

// To compile with NVIDIA CUDA compiler:
// nvcc -O3 cuda_benchmark.cu -o cuda_benchmark.exe

#ifdef __CUDACC__
#include <cuda_runtime.h>

// CUDA Kernel: This function executes in parallel across thousands of GPU cores!
__global__ void gpuVectorAdd(const float* a, const float* b, float* c, int n) {
    int idx = blockDim.x * blockIdx.x + threadIdx.x;
    if (idx < n) {
        // Heavy math operation performed on each element
        c[idx] = sinf(a[idx]) * cosf(b[idx]) + sqrtf(fabsf(a[idx] * b[idx]));
    }
}
#endif

void cpuVectorAdd(const std::vector<float>& a, const std::vector<float>& b, std::vector<float>& c, int n) {
    for (int i = 0; i < n; i++) {
        c[i] = sinf(a[i]) * cosf(b[i]) + sqrtf(fabsf(a[i] * b[i]));
    }
}

int main() {
    const int N = 50000000; // 50 Million elements! (~600 MB of data)
    std::cout << "Allocating and benchmarking 50,000,000 elements...\n" << std::endl;

    // Allocate host (CPU) memory
    std::vector<float> h_a(N, 1.5f);
    std::vector<float> h_b(N, 2.5f);
    std::vector<float> h_c_cpu(N, 0.0f);

    // 1. Benchmark CPU
    std::cout << "Running on CPU (Single-thread)..." << std::endl;
    auto start_cpu = std::chrono::high_resolution_clock::now();
    cpuVectorAdd(h_a, h_b, h_c_cpu, N);
    auto end_cpu = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> cpu_duration = end_cpu - start_cpu;
    std::cout << "CPU Time: " << cpu_duration.count() << " ms\n" << std::endl;

#ifdef __CUDACC__
    // 2. Benchmark GPU (NVIDIA RTX 4050 CUDA)
    std::cout << "Running on GPU (NVIDIA CUDA Kernels)..." << std::endl;
    float *d_a, *d_b, *d_c;
    size_t bytes = N * sizeof(float);

    // Allocate GPU Device VRAM
    cudaMalloc(&d_a, bytes);
    cudaMalloc(&d_b, bytes);
    cudaMalloc(&d_c, bytes);

    // Copy data from CPU RAM -> GPU VRAM
    cudaMemcpy(d_a, h_a.data(), bytes, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b.data(), bytes, cudaMemcpyHostToDevice);

    // Launch CUDA Kernel across thousands of parallel threads
    int threadsPerBlock = 256;
    int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;

    auto start_gpu = std::chrono::high_resolution_clock::now();
    gpuVectorAdd<<<blocksPerGrid, threadsPerBlock>>>(d_a, d_b, d_c, N);
    cudaDeviceSynchronize(); // Wait for all GPU cores to finish
    auto end_gpu = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> gpu_duration = end_gpu - start_gpu;
    std::cout << "GPU Time: " << gpu_duration.count() << " ms" << std::endl;

    double speedup = cpu_duration.count() / gpu_duration.count();
    std::cout << "\n>>> GPU was " << speedup << "x faster than CPU! <<<\n" << std::endl;

    // Free GPU VRAM
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
#else
    std::cout << "[Note] Compiled with standard C++ compiler (CPU-only)." << std::endl;
    std::cout << "To run on NVIDIA GPU: install NVIDIA CUDA Toolkit and compile with 'nvcc'." << std::endl;
#endif

    return 0;
}
