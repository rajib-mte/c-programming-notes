# Format Specifiers in C Programming

## 1. Introduction

A **format specifier** is a special symbol used in C input/output functions (`printf()`, `scanf()`, etc.) to tell the compiler:

> **What type of data is being processed and how it should be interpreted.**

Format specifiers always begin with the percentage symbol:

```c
%
```

Example:

```c
printf("%d", age);
```

Here:

* `%d` → tells `printf()` that an integer value is coming
* `age` → the integer variable to print

---

# 2. Why Format Specifiers Are Required?

Computers store all data as binary values. The same binary data can represent different types.

Example:

```c
int value = 65;
```

Memory:

```
01000001
```

This value can represent:

```
Integer:    65
Character:  'A'
Hex:        0x41
```

The format specifier tells C how to interpret the data.

Example:

```c
int value = 65;

printf("%d", value);
```

Output:

```
65
```

```c
printf("%c", value);
```

Output:

```
A
```

Same data, different interpretation.

---

# 3. Format Specifiers in `printf()` and `scanf()`

Format specifiers are used in:

## Output

```c
printf()
```

Example:

```c
printf("%d", number);
```

## Input

```c
scanf()
```

Example:

```c
scanf("%d",&number);
```

---

# 4. Integer Format Specifiers

## `%d` — Signed Decimal Integer

Used for:

```c
int
```

Example:

```c
#include <stdio.h>

int main()
{
    int age = 25;

    printf("%d", age);

    return 0;
}
```

Output:

```
25
```

---

## `%i` — Signed Integer

Similar to `%d`.

Example:

```c
int number = 100;

printf("%i", number);
```

Output:

```
100
```

Difference appears in `scanf()` when reading different bases.

Example:

```c
scanf("%i",&number);
```

Input:

```
010
```

Interpreted as:

```
Octal 10 = Decimal 8
```

---

## `%u` — Unsigned Integer

Used for:

```c
unsigned int
```

Example:

```c
unsigned int count = 100;

printf("%u", count);
```

Output:

```
100
```

---

# 5. Short and Long Integer Specifiers

## `%hd` — Short Integer

Example:

```c
short int value = 100;

printf("%hd", value);
```

---

## `%ld` — Long Integer

Example:

```c
long int population = 8000000;

printf("%ld", population);
```

---

## `%lld` — Long Long Integer

Example:

```c
long long int distance = 9000000000;

printf("%lld", distance);
```

---

# 6. Floating Point Format Specifiers

## `%f` — Float

Example:

```c
float temperature = 36.5;

printf("%f", temperature);
```

Output:

```
36.500000
```

---

## Controlling Decimal Places

Syntax:

```c
%.numberf
```

Example:

```c
float pi = 3.141592;

printf("%.2f",pi);
```

Output:

```
3.14
```

---

## `%lf` — Double in scanf()

For `scanf()`:

```c
double value;

scanf("%lf",&value);
```

Important:

### printf()

```c
printf("%f",double_value);
```

### scanf()

```c
scanf("%lf",&double_value);
```

---

# 7. Character Format Specifier

## `%c`

Used for:

```c
char
```

Example:

```c
char grade = 'A';

printf("%c", grade);
```

Output:

```
A
```

---

ASCII Example:

```c
char ch = 65;

printf("%c", ch);
```

Output:

```
A
```

---

# 8. String Format Specifier

## `%s`

Used for:

```c
character array
```

Example:

```c
char name[] = "Rajib";

printf("%s",name);
```

Output:

```
Rajib
```

---

Memory:

```
R  a  j  i  b  \0
```

`%s` prints until it finds:

```
\0
```

---

# 9. Hexadecimal Format Specifier

Hexadecimal is very important in embedded systems.

## `%x`

Lowercase hexadecimal:

```c
int value = 255;

printf("%x",value);
```

Output:

```
ff
```

---

## `%X`

Uppercase hexadecimal:

```c
printf("%X",value);
```

Output:

```
FF
```

---

Example:

```c
uint8_t register_value = 0x3A;

printf("Register = 0x%X", register_value);
```

Output:

```
Register = 0x3A
```

Useful for:

* MCU registers
* Memory addresses
* Debugging

---

# 10. Octal Format Specifier

## `%o`

Example:

```c
int value = 64;

printf("%o",value);
```

Output:

```
100
```

Because:

```
64 decimal = 100 octal
```

---

# 11. Pointer Format Specifier

## `%p`

Used for memory addresses.

Example:

```c
int number = 10;

printf("%p",&number);
```

Output:

```
0x7ffd23ab
```

Very useful for understanding:

* Pointers
* Memory
* Embedded debugging

---

# 12. Percentage Symbol

To print `%` itself:

Use:

```c
%%
```

Example:

```c
printf("Battery 90%%");
```

Output:

```
Battery 90%
```

---

# 13. Format Width

You can define minimum output width.

Example:

```c
printf("%5d",25);
```

Output:

```
   25
```

Total width:

```
5 characters
```

---

# 14. Left Alignment

Default:

```c
printf("%5d",25);
```

Output:

```
   25
```

Left aligned:

```c
printf("%-5d",25);
```

Output:

```
25   
```

---

# 15. Zero Padding

Example:

```c
printf("%05d",25);
```

Output:

```
00025
```

Common in:

* Time display
* IDs
* Counters

Example:

```c
printf("ID_%04d",7);
```

Output:

```
ID_0007
```

---

# 16. Format Specifiers with `scanf()`

Important difference:

`scanf()` usually requires addresses.

Example:

```c
int age;

scanf("%d",&age);
```

---

## Multiple Inputs

```c
int age;
float height;

scanf("%d %f",&age,&height);
```

Input:

```
25 5.8
```

---

# 17. Complete Format Specifier Table

| Format | Data Type        | Example      |
| ------ | ---------------- | ------------ |
| `%d`   | int              | 100          |
| `%i`   | int              | 100          |
| `%u`   | unsigned int     | 100          |
| `%hd`  | short int        | 10           |
| `%ld`  | long int         | 100000       |
| `%lld` | long long int    | large number |
| `%f`   | float            | 3.14         |
| `%lf`  | double (`scanf`) | 3.14159      |
| `%c`   | char             | A            |
| `%s`   | string           | Hello        |
| `%x`   | hexadecimal      | ff           |
| `%X`   | HEX uppercase    | FF           |
| `%o`   | octal            | 777          |
| `%p`   | pointer          | 0x1000       |
| `%%`   | percentage       | %            |

---

# 18. Embedded Systems Important Format Specifiers

For STM32, ESP32, AVR:

## Printing Register Values

```c
uint32_t reg = 0x40021000;

printf("Register = 0x%08X",reg);
```

Output:

```
Register = 0x40021000
```

---

## Printing Sensor Data

```c
int temperature = 28;

printf("Temperature = %d C\r\n",temperature);
```

Output:

```
Temperature = 28 C
```

---

## Printing Memory Address

```c
uint8_t buffer[10];

printf("Address = %p",buffer);
```

Output:

```
Address = 0x20000000
```

---

# 19. Common Mistakes

## Mistake 1: Wrong format

Wrong:

```c
float voltage = 3.3;

printf("%d",voltage);
```

Correct:

```c
printf("%f",voltage);
```

---

## Mistake 2: Missing `&` in scanf

Wrong:

```c
int value;

scanf("%d",value);
```

Correct:

```c
scanf("%d",&value);
```

---

## Mistake 3: Wrong string format

Wrong:

```c
char name[]="Rajib";

printf("%c",name);
```

Correct:

```c
printf("%s",name);
```

---

# 20. Relationship Between Data Type and Format Specifier

```
Data Type          Format Specifier

char        --->   %c
int         --->   %d
float       --->   %f
double      --->   %lf (scanf)
string      --->   %s
address     --->   %p
hex         --->   %x
```

---

# 21. Professional Programming Rule

Always match:

```
Variable Type
       |
       |
       v
Correct Format Specifier
       |
       |
       v
printf()/scanf()
```

Example:

```c
uint16_t adc_value;

printf("%u",adc_value);
```

Not:

```c
printf("%f",adc_value);
```

---

# Summary

Format specifiers are the communication language between your **C variables** and **input/output functions**.

They tell C:

* What type of data exists
* How to convert it
* How to display or read it

For embedded systems, mastering format specifiers is essential because debugging often depends on displaying:

* Sensor values
* Memory addresses
* Registers
* Communication packets
* System states

A strong C programmer always knows:

> **Data type + correct format specifier = reliable input/output handling**.
