# push_swap

`push_swap` is a 42 algorithmic project focused on sorting integers using two stacks and a limited set of operations. The objective is to find the most optimized sorting solution using the fewest moves possible.

## 🛠️ Project Overview

You must write a program that calculates and outputs the most efficient sequence of instructions to sort a stack of integers. A second program (`checker`) can be used to verify the validity of your solution.

## 📚 Key Concepts

- Sorting algorithms: selection, insertion, quicksort (pivot)
- Stack manipulation (LIFO)
- Instruction optimization and efficiency
- Handling of edge cases and large data sets

## ⚙️ Allowed Operations

- `sa`, `sb`, `ss` — swap the top two elements of stack A and/or B  
- `pa`, `pb` — push the top element from one stack to another  
- `ra`, `rb`, `rr` — rotate (first element becomes last)  
- `rra`, `rrb`, `rrr` — reverse rotate (last element becomes first)

## 💡 Usage

```bash
./push_swap 3 2 1 6 5 4
```

This will output a list of operations to sort the stack.

To test your output with the checker:

```bash
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
```

## 🔧 Compilation

Compile with:

```bash
make
```

## 📌 Notes

- No memory leaks allowed
- Must handle both small and large stacks efficiently
- Should output the minimal number of moves possible
- Must conform to the 42 Norm

