# 🟢 Belt 3 (Green Belt) — Complete Master Revision Guide

This document contains every single algorithmic pattern, mental model, edge case, and C++ code implementation you mastered during **Level 3 (Green Belt - Linear Data Handling & In-Place Algorithms)**.

---

## 📑 Table of Contents
1. [Dynamic Arrays & Vector Best Practices](#1-dynamic-arrays--vector-best-practices)
2. [2D Matrices & Grid Operations](#2-2d-matrices--grid-operations)
3. [Digit Extraction & State Management (Automorphic & Strong Numbers)](#3-digit-extraction--state-management)
4. [In-Place Two-Pointer Partitioning (0s/1s & Even/Odd)](#4-in-place-two-pointer-partitioning)
5. [In-Place Array Rotation (The 3-Step Reversal Algorithm)](#5-in-place-array-rotation-the-3-step-reversal-algorithm)
6. [Two-Array Traversal (Intersection & Union of Sorted Arrays)](#6-two-array-traversal-intersection--union)
7. [Target Triplet Sum (3Sum: O(N³) to O(N²) Two-Pointer Optimization)](#7-target-triplet-sum-3sum)
8. [Manual Sorting Algorithms (Bubble, Selection & Counting Sort)](#8-manual-sorting-algorithms)
9. [The SDE Hidden Test Case Checklist](#9-the-sde-hidden-test-case-checklist)

---

## 1. Dynamic Arrays & Vector Best Practices

### 🧠 The Core Mental Models:
* **Stack vs Heap:** `int arr[n]` allocates on the tiny Stack (~1MB) causing Stack Overflows on large inputs. `std::vector` allocates on the **Heap (Gigabytes of RAM)**.
* **Pre-Allocation vs `push_back`:**
  - If you know `n`, **always use `vector<int> v(n);` with `cin >> v[i];`** to avoid repeated RAM reallocations.
  - If using range-based input, you **MUST use `&` (reference)**: `for (int& ele : v) cin >> ele;`. Without `&`, `cin` writes to a throwaway copy!

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Optimal Heap Pre-Allocation:
    vector<int> arr(n);

    // Modern Range-Based Input:
    for (int& ele : arr) {
        cin >> ele;
    }

    // Modern Range-Based Output:
    for (int ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
```

---

## 2. 2D Matrices & Grid Operations

### 🧠 The Core Mental Model:
* A 2D matrix is indexed as `matrix[row][col]`.
* Outer loop iterates over rows (`i = 0 to m-1`), inner loop iterates over columns (`j = 0 to n-1`).

### 📌 Problem: Coordinate Tracking for Max Element
```cpp
#include <iostream>
#include <vector>
using namespace std;

void findMaxCoordinates(const vector<vector<int>>& mat, int m, int n) {
    int maxVal = mat[0][0];
    int maxRow = 0;
    int maxCol = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] > maxVal) {
                maxVal = mat[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    cout << "Max Value: " << maxVal << " at (" << maxRow << ", " << maxCol << ")" << endl;
}
```

---

## 3. Digit Extraction & State Management

### 🧠 The Core Mental Models:
1. **Digit Extraction:** `N % 10` extracts the last digit; `N / 10` chops off the last digit.
2. **The `original` Preservation Rule:** `while (temp > 0)` destroys `temp` down to 0. Always keep a copy of the original number before checking `if (original == sum)`.
3. **The 0-Loop O(1) Factorial Table:** A single digit can only be 0 to 9. Precomputing `factTable[10]` avoids slow loops!

### 📌 Problem: Strong Number (Sum of digit factorials == Number)
```cpp
#include <iostream>
using namespace std;

bool isStrongNumber(int N) {
    // Instant O(1) Factorial Lookup Table for digits 0-9:
    int factTable[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

    int original = N;
    int sum = 0;

    while (N > 0) {
        int digit = N % 10;
        sum += factTable[digit]; // O(1) instant lookup
        N /= 10;
    }

    return (sum == original);
}
```

---

## 4. In-Place Two-Pointer Partitioning

### 🧠 The Core Mental Model (The 2-Wall Guarantee):
* **Left Pointer `i`:** Only advances (`i++`) when elements belong on the left (e.g. `0`s or Evens).
* **Right Pointer `j`:** Only retreats (`j--`) when elements belong on the right (e.g. `1`s or Odds).
* **When both are misplaced:** Swap them and advance both (`i++; j--;`).
* **Loop stops at `while (i < j)`:** Once pointers cross, the entire array is mathematically guaranteed to be partitioned in a single O(N) pass with O(1) space!

### 📌 Problem A: Sort 0s and 1s In-Place
```cpp
#include <iostream>
#include <vector>
using namespace std;

void sortZeroesAndOnes(vector<int>& v) {
    int i = 0;
    int j = v.size() - 1;

    while (i < j) {
        if (v[i] == 0) {
            i++;
        }
        else if (v[j] == 1) {
            j--;
        }
        else {
            // v[i] == 1 and v[j] == 0 -> SWAP!
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }
}
```

### 📌 Problem B: Sort Array by Parity (Evens First, Odds Last) [LeetCode 905]
```cpp
#include <iostream>
#include <vector>
using namespace std;

void sortEvenThenOdd(vector<int>& v) {
    int i = 0;
    int j = v.size() - 1;

    while (i < j) {
        if (v[i] % 2 == 0) {
            i++;
        }
        else if (v[j] % 2 != 0) {
            j--;
        }
        else {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }
}
```

---

## 5. In-Place Array Rotation (The 3-Step Reversal Algorithm)

### 🧠 The Core Mental Models:
1. **Circular Modulo Wrapping:** If d >= n, rotating by d is the same as rotating by `d % n`.
2. **The 3-Step Reversal Magic:**
   - **Step 1:** Reverse first d elements (`0` to `d - 1`).
   - **Step 2:** Reverse remaining elements (`d` to `n - 1`).
   - **Step 3:** Reverse the ENTIRE array (`0` to `n - 1`).

### 📌 Problem: Left Rotate Array by d Positions [LeetCode 189]
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Reusable custom in-place sub-array reversal:
void myReverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void leftRotate(int arr[], int n, int d) {
    if (n <= 1) return; // Edge case: 0 or 1 element
    d = d % n;          // Circular wrapping
    if (d == 0) return; // No rotation needed

    // The 3-Step Reversal:
    myReverse(arr, 0, d - 1); // 1. Reverse first d elements
    myReverse(arr, d, n - 1); // 2. Reverse remaining elements
    myReverse(arr, 0, n - 1); // 3. Reverse entire array!
}
```

---

## 6. Two-Array Traversal (Intersection & Union)

### 🧠 The Core Mental Model:
* Two fingers (`i` on `arr1`, `j` on `arr2`).
* Advance whichever pointer points to the **smaller value**.
* When values match, process and advance both.

### 📌 Problem A: Intersection of Two Sorted Arrays (Common Elements)
```cpp
#include <iostream>
#include <vector>
using namespace std;

void findIntersection(const vector<int>& arr1, const vector<int>& arr2) {
    int i = 0;
    int j = 0;
    bool foundAny = false;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            foundAny = true;

            int currentVal = arr1[i];
            // Fast-forward past duplicate copies:
            while (i < arr1.size() && arr1[i] == currentVal) i++;
            while (j < arr2.size() && arr2[j] == currentVal) j++;
        }
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    if (!foundAny) cout << -1;
    cout << endl;
}
```

### 📌 Problem B: Union of Two Sorted Arrays (All Unique Elements Merged)
```cpp
#include <iostream>
#include <vector>
using namespace std;

void findUnion(const vector<int>& arr1, const vector<int>& arr2) {
    int i = 0;
    int j = 0;
    vector<int> result;

    auto pushUnique = [&](int val) {
        if (result.empty() || result.back() != val) {
            result.push_back(val);
        }
    };

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            pushUnique(arr1[i]);
            i++;
        }
        else if (arr2[j] < arr1[i]) {
            pushUnique(arr2[j]);
            j++;
        }
        else {
            pushUnique(arr1[i]);
            i++;
            j++;
        }
    }

    // Flush remaining leftovers:
    while (i < arr1.size()) { pushUnique(arr1[i]); i++; }
    while (j < arr2.size()) { pushUnique(arr2[j]); j++; }

    for (int x : result) cout << x << " ";
    cout << endl;
}
```

---

## 7. Target Triplet Sum (3Sum)

### 🧠 The Optimization:
* **Brute Force (3 nested loops):** O(N³) time complexity -> Causes TLE on large tests.
* **Two-Pointer Optimization:** Sort array first (O(N log N)), fix 1st number with `for` loop `i`, and search remaining 2 numbers with `left` and `right` pointers in O(N²) time!

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countTriplets(vector<int>& arr, int targetsum) {
    int n = arr.size();
    sort(arr.begin(), arr.end()); // Mandatory for Two-Pointers!
    int count = 0;

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = arr[i] + arr[left] + arr[right];

            if (currentSum == targetsum) {
                count++;
                left++;
                right--;
            }
            else if (currentSum < targetsum) {
                left++; // Need a larger sum
            }
            else {
                right--; // Need a smaller sum
            }
        }
    }

    return count;
}
```

---

## 8. Manual Sorting Algorithms

### 🧠 The Swap Memory Anchor:
> **`temp = A;  A = B;  B = temp;`** *(Diagonal slide pattern)*

### A. Bubble Sort (Adjacent Comparisons - O(N²))
```cpp
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

### B. Selection Sort (Find Minimum & Place at Front - O(N²))
```cpp
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}
```

### C. The 26-Bucket Alphabet Counting Sort (O(N) Linear Time)
```cpp
string sortAlphabets(string s) {
    int count[26] = {0};

    for (char ch : s) {
        count[ch - 'a']++;
    }

    string sorted = "";
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            sorted += (char)('a' + i);
            count[i]--;
        }
    }
    return sorted;
}
```

---

## 9. The SDE Hidden Test Case Checklist

Run through these **4 questions** before submitting any test:

1. **The Single-Item Trap (N = 0 or N = 1):**
   - Will `n - 1` or `d - 1` become negative or access illegal memory?
2. **The Giant Parameter (D >= N):**
   - Did I do `d = d % n`?
3. **The Duplicates Trap:**
   - What if all elements are identical (e.g. `[0, 0, 0, 0]`)? Will pointers deadlock?
4. **The Integer Overflow Trap:**
   - Will products/sums exceed 2 Billion? Do I need `long long`?

---
*Created for Faheem's C++ & DSA Learning Journey 🚀*
