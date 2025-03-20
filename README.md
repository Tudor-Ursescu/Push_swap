# Push_swap - Sorting algorithm challenge

## 📌 Overview

**push_swap** is a sorting algorithm challenge designed to sort a stack of integers using the fewest number of operations. It is often used in coding challenges or as part of coding curriculum (such as at 42). The challenge requires implementing sorting using two stacks (a and b), where the goal is to move numbers around and eventually sort the integers in stack a.

## ⚡ Features
- Implements sorting algorithms using only push, swap, and rotate operations.
- Optimized for minimal operations to achieve sorted order.

## Operations
- sa: Swap the first two elements of stack a.
- sb: Swap the first two elements of stack b.
- ss: Perform sa and sb simultaneously.
- pa: Push the top element of stack b onto stack a.
- pb: Push the top element of stack a onto stack b.
- ra: Rotate stack a (move the top element to the bottom).
- rb: Rotate stack b (move the top element to the bottom).
- rr: Perform ra and rb simultaneously.
- rra: Reverse rotate stack a (move the bottom element to the top).
- rrb: Reverse rotate stack b (move the bottom element to the top).
- rrr: Perform rra and rrb simultaneously.

## 🚫 Edge Cases 
- Non-numeric input: Any non-integer values will result in an error.
- Duplicate values: Duplicate integers in the input will cause an error.
- Values out of integer range: Inputs exceeding the minimum or maximum integer limits,
  such as 2147483649 or 2147483648.
- Leading/trailing spaces: Input with extra spaces (e.g., " 1 2 3 ") should still be handled   correctly.
- Negative numbers: Input containing negative integers (e.g., "-5 3 2") should be processed as valid

## 📂 Directory Structure
```
push_swap/
├── includes/        # Header files
├── src/             # Source code
├── Makefile         # Compilation automation
└── README.md        # Project documentation
```

## 🚀 Installation
To compile and use Push_swap in your own projects:
```sh
git clone https://github.com/Tudor-Ursescu/Push_swap.git
cd Push_swap
make
```
This will produce the executable `push_swap`.

## 🛠️ Usage
After compiling, you can use the program by running:
```sh
./push_swap [numbers]
```
The input can be provided as a single argument with space-separated integers (e.g., "3 2 1") or as multiple individual arguments, each separated by one or more spaces.


## 📜 License
This project is open-source.

## 👤 Author
[**Tudor Ursescu**](https://github.com/Tudor-Ursescu)