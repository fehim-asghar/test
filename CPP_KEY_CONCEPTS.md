# 🧠 C++ Key Concepts & Intuition Notes

This document contains core architectural insights, golden rules, and mental models for C++ revision.

---

## 🔑 Golden Rule 1: Header Files vs Compiler (`g++`)

> **"A Header File (`.h`) is just PERMISSION. In `g++`, you still have to pass the `.cpp` file wherever the actual function body lives!"**

### 💡 How it works under the hood:
1. **`#include "file.h"`** = Preprocessor copy-pastes the forward declaration. It gives the current file permission/syntax clearance to compile. It does **NOT** search your computer for the body!
2. **`g++ file1.cpp file2.cpp -o app.exe`** = You MUST feed all `.cpp` files containing function bodies to `g++` so the **Linker** can connect the calls to the actual bodies.
3. **If you forget the `.cpp` file in `g++`:** You get the famous Linker Error: `undefined reference to 'function_name()'`.

---

## 🔑 Golden Rule 2: Undefined Behavior & Initialization

> **"C++ does NOT clean RAM for you. Uninitialized variables (`int x;`) hold random garbage data!"**

- **Always use Direct-List Initialization:** `int x { 5 };` or `int x {};` (defaults to 0).
- Avoid `int x;` without initialization to prevent silent bugs in Data Structures algorithms!

---

## 🔑 Golden Rule 3: Integer Division vs Modulo

- **`7 / 2`** = `3` (Integer division truncates/discards the decimal completely).
- **`7 % 2`** = `1` (Modulo `%` gives the remainder).
- **DSA Uses:** `% 2 == 0` for Even/Odd, `index % size` for Circular Array looping.
