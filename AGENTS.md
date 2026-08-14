# Agent Instructions for C++ Learning Journey

## Project Overview
This workspace is a **C++ learning project** following the [LearnCPP.com](https://www.learncpp.com) curriculum (60-day roadmap, Chapters 0–25). The goal is to build a solid foundation in C++ fundamentals and progress toward DSA (Data Structures & Algorithms) preparation.

### Key Tracking Documents
- **[LEARNCPP_TRACKER.md](LEARNCPP_TRACKER.md)** — Official progress through all chapters (marked ✅ when complete)
- **[CPP_KEY_CONCEPTS.md](CPP_KEY_CONCEPTS.md)** — Golden rules, mental models, and architectural insights
- **cpp_journey/** — Practical code examples and exercises

---

## Core Learning Principles

### 🔑 Golden Rule 1: Header Files vs Compilation
> A `.h` file is *permission only*. The linker needs the `.cpp` file with the function body.
- `#include "file.h"` → Preprocessor copies the forward declaration (syntax clearance)
- `g++ file1.cpp file2.cpp -o app.exe` → Linker connects calls to actual implementations
- Missing `.cpp` file → **Linker Error: `undefined reference`**

### 🔑 Golden Rule 2: No Automatic RAM Cleanup
> Uninitialized variables hold random garbage. Always use direct-list initialization.
- ✅ Use: `int x { 5 };` or `int x {};` (defaults to 0)
- ❌ Avoid: `int x;` (undefined behavior, critical for DSA)

### 🔑 Golden Rule 3: Integer Division vs Modulo
- `7 / 2` = `3` (truncates decimal)
- `7 % 2` = `1` (remainder)
- DSA Uses: `% 2 == 0` for parity, `index % size` for circular arrays

---

## How to Help

### When Writing or Reviewing Code
- **Validate header/implementation splits** — Ensure all `.cpp` implementations are listed in compilation commands
- **Check initialization** — Flag uninitialized variables, especially in loops and DSA work
- **Clarify operators** — Explain integer division vs float division, modulo usage patterns
- **Build/test commands** — Run: `g++ cpp_journey/*.cpp -o app.exe && ./app.exe`

### When Explaining Concepts
- Reference the **golden rules** in [CPP_KEY_CONCEPTS.md](CPP_KEY_CONCEPTS.md) first
- Connect new concepts to [LEARNCPP_TRACKER.md](LEARNCPP_TRACKER.md) chapter context
- Use mental models (compiler flow, linker behavior, memory layout) from the key concepts doc
- Provide small, isolated examples that demonstrate one principle at a time

### When Helping with Exercises
- Verify the exercise aligns with the **current chapter** in LEARNCPP_TRACKER
- Avoid skipping ahead to advanced chapters unless requested
- Encourage using direct-list initialization and proper header/cpp separation from the start
- Suggest building/testing locally with the compilation command above

---

## Project Structure
```
padhai/
├── LEARNCPP_TRACKER.md       → Progress (chapters 0–25)
├── CPP_KEY_CONCEPTS.md       → Mental models & golden rules
├── cpp_journey/
│   ├── main.cpp              → Practice entry point
│   ├── math.cpp / math.h     → Example header/implementation split
│   └── ...                   → Future chapters & exercises
└── GIT_CHEAT_SHEET.md, etc.  → Supporting notes
```

---

## Current Progress
Chapters 0–3 completed ✅ (Getting Started, Basics, Functions & Headers, Debugging)

**Next Focus:** Continue through Chapter 4+ as marked in LEARNCPP_TRACKER.md, reinforcing header/implementation patterns and building toward DSA preparation.

---

## Related Resources
- [LEARNCPP_TRACKER.md](LEARNCPP_TRACKER.md) — Detailed chapter breakdown
- [CPP_KEY_CONCEPTS.md](CPP_KEY_CONCEPTS.md) — Core mental models
- [GIT_CHEAT_SHEET.md](GIT_CHEAT_SHEET.md) — Git workflows
