# `printf()` Function in C Programming

## 1. Introduction

`printf()` is one of the most commonly used functions in the C programming language. It is used to **display formatted output** on the standard output device (normally the computer screen).

The name `printf` means:

> **print formatted**

It belongs to the standard input/output library:

```c
#include <stdio.h>
```

The `printf()` function allows programmers to print:

* Text messages
* Numbers
* Characters
* Floating-point values
* Variable values
* Formatted data

It is essential for:

* Learning C programming
* Debugging programs
* Embedded system development
* Microcontroller firmware debugging

---

# 2. Basic Syntax

```c
printf("format string", arguments);
```

### Example:

```c
#include <stdio.h>

int main()
{
    printf("Hello World");

    return 0;
}
```

### Output:

```
Hello World
```

---

# 3. How `printf()` Works Internally

When the compiler sees:

```c
printf("Temperature: %d", temp);
```

The process is:

```
C Program
    |
    |
    v
printf()
    |
    |
    v
Convert data according to format specifier
    |
    |
    v
Send characters to stdout
    |
    |
    v
Terminal / Console Display
```

`printf()` does not directly understand variables. It needs **format specifiers** to know:

* What type of data is coming
* How to convert the data
* How many bytes to read from memory

---

# 4. Format Specifiers

Format specifiers start with `%`.

Example:

```c
printf("%d", number);
```

`%d` tells `printf()`:

> "The given value is an integer."

---

# 5. Common Format Specifiers

| Specifier | Data Type             | Example |
| --------- | --------------------- | ------- |
| `%d`      | signed integer        | 100     |
| `%i`      | signed integer        | 100     |
| `%u`      | unsigned integer      | 100     |
| `%f`      | float                 | 3.14    |
| `%lf`     | double                | 3.14159 |
| `%c`      | character             | A       |
| `%s`      | string                | Hello   |
| `%x`      | hexadecimal           | FF      |
| `%X`      | uppercase hexadecimal | FF      |
| `%o`      | octal                 | 777     |
| `%p`      | pointer address       | 0x1000  |

---

# 6. Printing Integer Values

Example:

```c
#include <stdio.h>

int main()
{
    int age = 25;

    printf("Age = %d", age);

    return 0;
}
```

Output:

```
Age = 25
```

---

## Multiple Integer Printing

```c
#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;

    printf("a = %d, b = %d", a, b);

    return 0;
}
```

Output:

```
a = 10, b = 20
```

---

# 7. Printing Floating Point Numbers

## Float

```c
#include <stdio.h>

int main()
{
    float voltage = 3.3;

    printf("Voltage = %f", voltage);

    return 0;
}
```

Output:

```
Voltage = 3.300000
```

---

## Controlling Decimal Places

Syntax:

```c
%.number_of_digitsf
```

Example:

```c
float pi = 3.141592;

printf("%.2f", pi);
```

Output:

```
3.14
```

More examples:

```c
printf("%.3f", pi);
```

Output:

```
3.142
```

---

# 8. Printing Characters

A character uses `%c`.

Example:

```c
#include <stdio.h>

int main()
{
    char grade = 'A';

    printf("Grade = %c", grade);

    return 0;
}
```

Output:

```
Grade = A
```

---

# 9. Printing Strings

A string is an array of characters.

Example:

```c
#include <stdio.h>

int main()
{
    char name[] = "Rajib";

    printf("Name = %s", name);

    return 0;
}
```

Output:

```
Name = Rajib
```

---

# 10. Printing Memory Address

Pointers store memory addresses.

`%p` is used for printing addresses.

Example:

```c
#include <stdio.h>

int main()
{
    int value = 10;

    printf("Address = %p", &value);

    return 0;
}
```

Output:

```
Address = 0x7ffd23ab
```

---

# 11. Escape Sequences with printf()

Escape sequences control formatting.

| Escape | Meaning         |
| ------ | --------------- |
| `\n`   | New line        |
| `\t`   | Tab             |
| `\\`   | Backslash       |
| `\"`   | Double quote    |
| `\r`   | Carriage return |

---

Example:

```c
#include <stdio.h>

int main()
{
    printf("Hello\nWorld");

    return 0;
}
```

Output:

```
Hello
World
```

---

# 12. Printing Tables

Example:

```c
#include <stdio.h>

int main()
{
    printf("Name\tAge\n");
    printf("Rajib\t25\n");

    return 0;
}
```

Output:

```
Name    Age
Rajib   25
```

---

# 13. Width Control

You can specify minimum output width.

Example:

```c
printf("%5d", 25);
```

Output:

```
   25
```

The number occupies 5 spaces.

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

Useful for:

* Time display
* Counters
* Device IDs

Example:

```c
printf("ID_%04d",5);
```

Output:

```
ID_0005
```

---

# 16. Printing Hexadecimal

Hexadecimal is very important in embedded systems.

Example:

```c
int address = 255;

printf("%x", address);
```

Output:

```
ff
```

Uppercase:

```c
printf("%X", address);
```

Output:

```
FF
```

---

# 17. Printing Binary Numbers

C `printf()` does not have a direct binary format specifier.

Example:

```c
printf("%d",10);
```

Output:

```
10
```

For binary:

```
00001010
```

You need a custom function.

---

# 18. Return Value of printf()

`printf()` returns the number of characters printed.

Example:

```c
#include <stdio.h>

int main()
{
    int count;

    count = printf("Hello");

    printf("\nCharacters printed = %d", count);

    return 0;
}
```

Output:

```
Hello
Characters printed = 5
```

---

# 19. Common Mistakes

## Mistake 1: Wrong format specifier

Wrong:

```c
float value = 3.14;

printf("%d", value);
```

Correct:

```c
printf("%f", value);
```

---

## Mistake 2: Missing variable

Wrong:

```c
printf("%d");
```

The compiler expects an integer but receives nothing.

---

## Mistake 3: Printing string incorrectly

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

# 20. `printf()` in Embedded Systems

In microcontrollers like:

* STM32
* ESP32
* AVR
* PIC

there is usually no terminal.

So `printf()` output is redirected to:

* UART
* USB Virtual COM Port
* SWO Debug Interface
* RTT Debugger
* LCD/OLED Display

Example:

```
STM32
 |
 |
printf()
 |
 |
UART
 |
 |
Serial Monitor
```

---

## STM32 Example Concept

```c
printf("Temperature = %d C\r\n", temperature);
```

Output:

```
Temperature = 28 C
```

Received through UART terminal.

---

# 21. printf() Memory Cost in Embedded Systems

In embedded development, normal `printf()` can consume:

* Large Flash memory
* More RAM
* More execution time

Example:

STM32F103:

```
Without printf:
Flash usage = 15 KB

With printf:
Flash usage = 35 KB+
```

Because printf supports:

* Floating point conversion
* Formatting
* Multiple data types

---

# 22. Embedded Optimization Techniques

## Disable Float Support

Instead of:

```c
printf("Voltage %.2f", voltage);
```

Use:

```c
printf("Voltage %d mV", voltage_mv);
```

---

## Use Lightweight Alternatives

Examples:

```c
puts()
```

or:

```c
UART_SendString()
```

Custom embedded logging:

```c
LOG_INFO("Motor Started");
```

---

# 23. Difference Between printf() and puts()

| printf()           | puts()             |
| ------------------ | ------------------ |
| Formatted output   | Only string output |
| Supports variables | No formatting      |
| Slower             | Faster             |
| More memory        | Less memory        |

Example:

```c
puts("Hello");
```

Equivalent:

```c
printf("Hello\n");
```

---

# 24. Professional Embedded Debug Example

```c
#define DEBUG 1

#if DEBUG

#define LOG(x) printf x

#else

#define LOG(x)

#endif


int main()
{
    int sensor = 25;

    LOG(("Sensor value=%d\r\n",sensor));

    return 0;
}
```

When debugging:

```
Sensor value=25
```

When release build:

```
No debug output
```

---

# 25. Key Learning Points

After mastering `printf()` you should understand:

✅ Standard output
✅ Format specifiers
✅ Data type conversion
✅ Escape sequences
✅ Memory address printing
✅ Debugging technique
✅ UART redirection
✅ Embedded logging concepts

---

# Summary

`printf()` is not only a screen printing function. It is a powerful **formatted data conversion and debugging mechanism**. For normal C programming, it helps understand program behavior. For embedded systems, it becomes a foundation for creating professional debugging systems using UART, SWO, and logging frameworks.

Mastering `printf()` is an important first step toward becoming a strong **C programmer and embedded firmware engineer**.
