# 7. Pointers

## Overview

Pointers are one of the most powerful and important features of the C programming language. A pointer is a variable that stores the **memory address** of another variable instead of storing its actual value.

Pointers enable efficient memory management, dynamic memory allocation, function parameter passing by reference, and direct hardware access. They are widely used in **embedded systems, operating systems, device drivers, robotics, firmware development, and data structures**.

---

# Learning Objectives

After completing this chapter, you should be able to:

* Understand memory addresses
* Declare and initialize pointers
* Use the address (`&`) and dereference (`*`) operators
* Perform pointer arithmetic
* Work with arrays and pointers
* Use pointers with functions and structures
* Understand dynamic memory allocation
* Avoid common pointer-related bugs
* Apply pointers in embedded systems and firmware development

---

# 7.1 Introduction to Pointers

* What is a Pointer?
* Why Use Pointers?
* Memory Addresses
* Variables vs Pointers
* Pointer Size
* Pointer Declaration
* Pointer Initialization
* Pointer Assignment

---

# 7.2 Memory Address

Learn how variables are stored in RAM.

Topics

* Memory Layout
* Variable Address
* Address Operator (`&`)
* Address Representation
* Hexadecimal Addresses

Example

```c
int age = 25;

printf("%p", (void *)&age);
```

---

# 7.3 Pointer Declaration

Learn how to declare pointers.

Topics

* Syntax
* Data Type Matching
* Pointer Naming Convention

Examples

```c
int *ptr;
char *ch;
float *fp;
double *dp;
```

---

# 7.4 Pointer Initialization

Topics

* Initialize with Variable Address
* Initialize with NULL
* Initialize Later

Example

```c
int age = 20;

int *ptr = &age;
```

---

# 7.5 Address Operator (`&`)

The address operator returns the memory address of a variable.

Example

```c
int x = 10;

printf("%p", (void *)&x);
```

---

# 7.6 Dereference Operator (`*`)

The dereference operator accesses the value stored at a memory address.

Example

```c
int x = 50;

int *ptr = &x;

printf("%d", *ptr);
```

Output

```
50
```

---

# 7.7 Pointer Types

## Integer Pointer

```c
int *ptr;
```

---

## Character Pointer

```c
char *ptr;
```

---

## Float Pointer

```c
float *ptr;
```

---

## Double Pointer

```c
double *ptr;
```

---

## Structure Pointer

```c
struct Student *ptr;
```

---

## Void Pointer

```c
void *ptr;
```

---

# 7.8 NULL Pointer

A NULL pointer points to no valid memory location.

Example

```c
int *ptr = NULL;
```

Uses

* Safe Initialization
* Error Checking
* Avoid Dangling Pointers

---

# 7.9 Void Pointer

A generic pointer that can store the address of any data type.

Example

```c
void *ptr;
```

---

# 7.10 Wild Pointer

A pointer that has been declared but not initialized.

Example

```c
int *ptr;
```

Never use wild pointers.

---

# 7.11 Dangling Pointer

A pointer that points to memory that has already been freed or is no longer valid.

Example

```c
free(ptr);

ptr = NULL;
```

---

# 7.12 Pointer Arithmetic

Topics

* Increment
* Decrement
* Addition
* Subtraction
* Difference Between Two Pointers

Example

```c
ptr++;

ptr--;

ptr + 2;

ptr - 1;
```

---

# 7.13 Pointer Comparison

Topics

* ==
* !=
* <
* >
* <=
* > =

---

# 7.14 Arrays and Pointers

Topics

* Relationship Between Arrays and Pointers
* Array Name as Pointer
* Pointer Traversal
* Pointer Indexing

Examples

```c
arr[i]

*(arr + i)
```

---

# 7.15 Pointer to Pointer

Topics

* Double Pointer
* Triple Pointer
* Multiple Indirection

Example

```c
int **ptr;
```

---

# 7.16 Pointer and Functions

Topics

* Passing Pointer to Function
* Returning Pointer
* Call by Reference
* Modifying Variables Through Pointer

Example

```c
void swap(int *a, int *b);
```

---

# 7.17 Pointer to Array

Topics

* Pointer to One-Dimensional Array
* Pointer to Two-Dimensional Array

Example

```c
int (*ptr)[10];
```

---

# 7.18 Array of Pointers

Topics

* Array of Integer Pointers
* Array of Character Pointers
* Array of Strings

Example

```c
char *names[5];
```

---

# 7.19 Function Pointer

Topics

* Function Address
* Function Pointer Declaration
* Calling Through Pointer
* Callback Functions

Example

```c
int (*operation)(int, int);
```

Applications

* Driver Development
* Callback Mechanism
* Interrupt Vector Table
* State Machine

---

# 7.20 Pointer to Function

Topics

* Passing Function as Argument
* Returning Function Pointer

---

# 7.21 Structure Pointer

Topics

* Pointer to Structure
* Arrow Operator (`->`)
* Structure Access

Example

```c
student->age
```

---

# 7.22 Constant Pointer

Topics

* Constant Pointer

Example

```c
int *const ptr = &x;
```

The pointer cannot point to another address.

---

# 7.23 Pointer to Constant

Topics

* Read-Only Data

Example

```c
const int *ptr = &x;
```

The data cannot be modified through the pointer.

---

# 7.24 Constant Pointer to Constant

Example

```c
const int *const ptr = &x;
```

Neither the pointer nor the data can be modified.

---

# 7.25 Dynamic Memory and Pointers

Topics

* malloc()
* calloc()
* realloc()
* free()

Relationship Between

* Heap
* Stack
* Pointer

---

# 7.26 Memory Layout

Topics

* Code Segment
* Data Segment
* BSS Segment
* Heap
* Stack

Understand where pointers point inside memory.

---

# 7.27 Common Pointer Mistakes

* Using Uninitialized Pointers
* Dereferencing NULL Pointers
* Dangling Pointers
* Wild Pointers
* Memory Leaks
* Double Free
* Invalid Pointer Arithmetic
* Returning Address of Local Variables
* Accessing Freed Memory

---

# 7.28 Pointers in Embedded Systems ⭐

Topics

* Memory-Mapped Registers
* Peripheral Access
* Register Addresses
* GPIO Register Programming
* Interrupt Vector Tables
* DMA Buffers
* Hardware Abstraction Layer (HAL)
* Device Drivers
* Volatile Pointers

Example

```c
#define GPIOA_ODR (*(volatile unsigned int *)0x48000014)
```

---

# 7.29 Best Practices

* Always initialize pointers.
* Use `NULL` for unused pointers.
* Check pointers before dereferencing.
* Free dynamically allocated memory when no longer needed.
* Set pointers to `NULL` after `free()`.
* Match pointer types with the data they point to.
* Minimize pointer arithmetic unless necessary.
* Prefer clear variable names (e.g., `dataPtr`, `bufferPtr`).

---

# 7.30 Practice Programs

### Beginner

* Print a variable using a pointer
* Swap two numbers using pointers
* Find the maximum of two numbers using pointers
* Reverse an array using pointers
* Calculate string length using pointers

### Intermediate

* Pointer arithmetic examples
* Array traversal with pointers
* Matrix traversal using pointers
* Pointer to structure
* Array of pointers

### Advanced

* Function pointer calculator
* Dynamic memory allocator demo
* Linked list using pointers
* Binary tree using pointers
* Callback function implementation
* Memory-mapped register simulation

---

# Summary

Pointers are fundamental to mastering C. They provide direct access to memory, enable efficient data manipulation, and form the foundation of advanced topics such as dynamic memory allocation, data structures, function callbacks, and embedded systems programming. A solid understanding of pointers is essential for careers in **embedded systems, firmware engineering, robotics, operating systems, and high-performance software development**.
