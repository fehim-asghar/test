# 🐍 Python Dojo Workout & Revision Tracker

This document stores every single Python question, concept, edge case, and clean solution from your **Kalvium Dojo Python Workouts** so you never lose them after tests!

---

## ⚡ Quick Python vs C++ Cheat Sheet
* **Input int:** `n = int(input())`
* **Input list:** `arr = list(map(int, input().split()))`
* **Loop (0 to n-1):** `for i in range(n):`
* **Loop (1 to n):** `for i in range(1, n + 1):`
* **Length:** `len(arr)` | **Max:** `max(arr)` | **Min:** `min(arr)`
* **Reverse list/string:** `arr[::-1]`
* **Fast swap:** `a, b = b, a`

---

## 📝 Workout Problem Log

### Problem 1: Even/Odd Range Classifier
* **Task:** Take integer `n`. Print `"BIG EVEN"` if $n > 10$ and even, `"SMALL EVEN"` if $n \le 10$ and even, else `"ODD"`.
* **Key Concept:** `if`, `elif`, `else` alignment and `and` operator.

```python
n = int(input())

if n > 10 and n % 2 == 0:
    print("BIG EVEN")
elif n <= 10 and n % 2 == 0:
    print("SMALL EVEN")
else:
    print("ODD")
```

---

### Problem 2: Sum of First N Numbers
* **Task:** Calculate $1 + 2 + 3 + \dots + N$.
* **Key Concept:** `range(1, n + 1)` (because range stopping value is exclusive!).

```python
n = int(input())
print(sum(range(1, n + 1)))
```

---

### Problem 4: Math Magician (Basic Arithmetic Operations)
* **Task:** Take two space-separated integers `num1` and `num2`. Print their Addition, Subtraction, Multiplication, and Integer Division on separate lines.
* **Input Format:** `5 3`
* **Output Format:**
  - Line 1: `8` (Addition)
  - Line 2: `2` (Subtraction)
  - Line 3: `15` (Multiplication)
  - Line 4: `1` (Integer Division `//`)
* **Key Concept:** `x // y` for integer division, and multiple `print()` statements or `sep="\n"`.

```python
# Method 1: Standard
x, y = map(int, input().split())

print(x + y)
print(x - y)
print(x * y)
print(x // y)

# Method 2: SDE 1-Line Way (Using sep="\n")
# print(x + y, x - y, x * y, x // y, sep="\n")
```

---

### Problem 5: Calculate Age (Functions & F-Strings)
* **Task:** Given `present_year` and `year_of_birth` on separate lines, calculate the age and output: `You are {age} years old!`.
* **Input Format:**
  ```text
  2024
  2003
  ```
* **Output Format:** `You are 21 years old!`
* **Key Concept:** 
  1. `def function_name(params):` for function definitions.
  2. `f"You are {age} years old!"` (Python **f-strings** for direct variable interpolation).

```python
def calculate_age(present_year, year_of_birth):
    age = present_year - year_of_birth
    return f"You are {age} years old!"

def main():
    present_year = int(input())
    year_of_birth = int(input())
    print(calculate_age(present_year, year_of_birth))

if __name__ == "__main__":
    main()
```

---

### Problem 6: Convert to Hours (Decimal Rounding)
* **Task:** Take seconds as input, convert to hours (`seconds / 3600`), and round to **3 decimal places**.
* **Input Format:** `300`
* **Output Format:** `0.083`
* **Key Concept:** 
  1. `round(value, 3)` (Rounds to 3 decimal places).
  2. `f"{value:.3f}"` (String format to always keep 3 decimal places).

```python
def convert_to_hours(seconds):
    hours = seconds / 3600
    # Note: Use f"{hours:.3f}" instead of round() because round() drops trailing zeros (1.0 instead of 1.000)
    return f"{hours:.3f}"

def main():
    seconds = int(input())
    print(convert_to_hours(seconds))

if __name__ == "__main__":
    main()
```

---

### Problem 7: Convert Temperature (Float Formatting & Unit Conversion)
* **Task:** Convert between Celsius and Fahrenheit. Round output to **2 decimal places** (`:.2f`).
* **Formulas:**
  - $C \to F$: `(temp * 9/5) + 32`
  - $F \to C$: `(temp - 32) * 5/9`
* **Key Concept:**
  1. `char` does **NOT** exist in Python! Use `unit = input().strip()`.
  2. Format to 2 decimal places using `f"{val:.2f}"`.

```python
def convert_temperature(temp, unit):
    if unit == 'C':
        fahrenheit = (temp * 9 / 5) + 32
        return f"{fahrenheit:.2f}"
    else:
        celsius = (temp - 32) * 5 / 9
        return f"{celsius:.2f}"

def main():
    temp = float(input())
    unit = input().strip()
    print(convert_temperature(temp, unit))

if __name__ == "__main__":
    main()
```

---

*(Whenever you get a new question in Dojo, paste the question/screenshot here and we will solve it and log it immediately!)* 🚀
