# `puts()` Function in C Programming

## 1. Introduction

`puts()` is a standard C library function used to **display a string (sequence of characters) on the standard output device** (normally the screen).

The name means:

> **put string**

It belongs to:

```c
#include <stdio.h>
```

`puts()` is mainly used for printing strings and is simpler than `printf()` when no formatting is required.

---

# 2. Basic Syntax

```c
puts(string);
```

Example:

```c
#include <stdio.h>

int main()
{
    puts("Hello World");

    return 0;
}
```

### Output:

```
Hello World
```

---

# 3. How `puts()` Works Internally

When you write:

```c
puts("Hello");
```

The process:

```
String Data
     |
     |
     v
   puts()
     |
     |
     v
Send characters one by one
     |
     |
     v
Add newline character '\n'
     |
     |
     v
Display on screen
```

Conceptually:

```c
puts("Hello");
```

works similar to:

```c
putchar('H');
putchar('e');
putchar('l');
putchar('l');
putchar('o');
putchar('\n');
```

---

# 4. Function Prototype

The function declaration is:

```c
int puts(const char *str);
```

Explanation:

| Part              | Meaning                      |
| ----------------- | ---------------------------- |
| `int`             | Returns success/error status |
| `puts`            | Function name                |
| `const char *str` | Pointer to string data       |

---

# 5. Printing a String

Example:

```c
#include <stdio.h>

int main()
{
    char name[] = "Rajib";

    puts(name);

    return 0;
}
```

Output:

```
Rajib
```

---

# 6. Automatic New Line Behavior

One important feature of `puts()`:

> `puts()` automatically adds a newline (`\n`) after printing.

Example:

```c
#include <stdio.h>

int main()
{
    puts("Hello");
    puts("World");

    return 0;
}
```

Output:

```
Hello
World
```

Equivalent to:

```c
printf("Hello\n");
printf("World\n");
```

---

# 7. `puts()` vs `printf()`

## Using `puts()`

```c
puts("Temperature Sensor");
```

Output:

```
Temperature Sensor
```

---

## Using `printf()`

```c
printf("Temperature Sensor\n");
```

Output:

```
Temperature Sensor
```

Both produce the same output.

---

# 8. Difference Between `puts()` and `printf()`

| Feature          | `puts()`            | `printf()`       |
| ---------------- | ------------------- | ---------------- |
| Purpose          | Print strings       | Formatted output |
| Input            | Only string         | Any data type    |
| New line         | Automatically added | Must add `\n`    |
| Format specifier | Not required        | Required         |
| Speed            | Faster              | Slower           |
| Memory usage     | Lower               | Higher           |

---

Example:

### `puts()`

```c
puts("Value");
```

### `printf()`

```c
printf("%s\n","Value");
```

---

# 9. Printing Variables

Example:

```c
#include <stdio.h>

int main()
{
    char message[] = "Embedded System";

    puts(message);

    return 0;
}
```

Output:

```
Embedded System
```

---

# 10. `puts()` Cannot Print Numbers Directly

Wrong:

```c
int value = 100;

puts(value);
```

Why?

Because `puts()` expects:

```c
char *
```

but receives:

```c
int
```

Correct:

```c
printf("%d", value);
```

or convert number to string:

```c
char buffer[20];

sprintf(buffer,"%d",value);

puts(buffer);
```

---

# 11. Return Value of `puts()`

`puts()` returns:

* Non-negative value → success
* `EOF` → error

Example:

```c
#include <stdio.h>

int main()
{
    int result;

    result = puts("Hello");

    printf("Return value = %d", result);

    return 0;
}
```

Output:

```
Hello
Return value = 5
```

(The exact return value is implementation dependent.)

---

# 12. Difference Between `puts()` and `putchar()`

| Feature  | `puts()`        | `putchar()`      |
| -------- | --------------- | ---------------- |
| Output   | String          | Single character |
| Input    | Character array | Character        |
| New line | Automatic       | No               |
| Example  | `puts("Hello")` | `putchar('H')`   |

Example:

```c
puts("ABC");
```

Output:

```
ABC
```

---

```c
putchar('A');
putchar('B');
putchar('C');
```

Output:

```
ABC
```

---

# 13. Printing Multiple Lines

Example:

```c
#include <stdio.h>

int main()
{
    puts("C Programming");
    puts("Embedded Systems");
    puts("STM32 Firmware");

    return 0;
}
```

Output:

```
C Programming
Embedded Systems
STM32 Firmware
```

---

# 14. Using `puts()` with String Arrays

Example:

```c
#include <stdio.h>

int main()
{
    char languages[3][20] =
    {
        "C",
        "C++",
        "Python"
    };

    puts(languages[0]);
    puts(languages[1]);
    puts(languages[2]);

    return 0;
}
```

Output:

```
C
C++
Python
```

---

# 15. String Processing Example

Example:

```c
#include <stdio.h>

int main()
{
    char text[] = "Hello Embedded World";

    puts(text);

    return 0;
}
```

Output:

```
Hello Embedded World
```

---

# 16. `puts()` and String Termination

Every C string must end with:

```c
'\0'
```

Example:

```c
char name[] = "Rajib";
```

Memory:

```
Index:

0    1    2    3    4    5
+----+----+----+----+----+----+
| R  | a  | j  | i  | b  |\0 |
+----+----+----+----+----+----+
```

`puts()` keeps printing until it finds:

```
'\0'
```

---

# 17. Common Mistakes

## Mistake 1: Passing a character

Wrong:

```c
puts('A');
```

Because:

```c
'A'
```

is a character.

Correct:

```c
putchar('A');
```

or:

```c
puts("A");
```

---

## Mistake 2: Forgetting string termination

Wrong:

```c
char text[5] = {'H','e','l','l','o'};

puts(text);
```

There is no:

```c
'\0'
```

Correct:

```c
char text[] = "Hello";
```

---

## Mistake 3: Expecting no newline

Code:

```c
puts("Hello");
puts("World");
```

Output:

```
Hello
World
```

If you need:

```
HelloWorld
```

use:

```c
printf("Hello");
printf("World");
```

---

# 18. `puts()` in Embedded Systems

In embedded systems:

* STM32
* ESP32
* AVR
* PIC

there is usually no screen.

`puts()` can be redirected to:

* UART
* USB CDC
* Debug console
* LCD/OLED display

Architecture:

```
Firmware
    |
    |
  puts()
    |
    |
 UART Driver
    |
    |
 Serial Monitor
```

---

# 19. STM32 UART Concept

Example:

```c
puts("Motor Started");
```

Output through UART:

```
Motor Started
```

Internally:

```
puts()
 |
 |
putchar()
 |
 |
HAL_UART_Transmit()
 |
 |
UART TX Pin
 |
 |
PC Terminal
```

---

# 20. Embedded Debug Logging Example

Instead of:

```c
printf("Sensor Value = %d\r\n",sensor);
```

For fixed messages:

```c
puts("Sensor Initialized");
```

Advantages:

* Less memory
* Faster execution
* Simple debugging

---

# 21. `puts()` vs UART String Function

Embedded developers often create:

```c
UART_SendString("Hello");
```

This is conceptually similar to:

```c
puts("Hello");
```

Flow:

```
String
  |
  |
Send characters one by one
  |
  |
UART TX
```

---

# 22. Basic C I/O Functions Relationship

```
              Output
                |
       -------------------
       |                 |
   printf()          puts()
       |                 |
       |              String
       |
   Formatted
       |
       |
   putchar()
       |
 Single Character


              Input
                |
       -------------------
       |                 |
    scanf()          fgets()
       |
       |
  Formatted

    getchar()
       |
 Single Character
```

---

# 23. When Should You Use `puts()`?

Use `puts()` when:

✅ Printing a fixed message
✅ Printing a string variable
✅ You need automatic newline
✅ You want lightweight output

Examples:

```c
puts("System Ready");
puts(sensor_name);
puts("Error!");
```

---

# 24. When Should You Not Use `puts()`?

Avoid when:

❌ Printing numbers directly

```c
puts(100);
```

❌ Need formatting

```c
Temperature = 25C
```

Use:

```c
printf("Temperature = %dC",25);
```

---

# 25. Key Learning Points

After learning `puts()` you should understand:

✅ String output
✅ Null-terminated strings
✅ Output streams
✅ Difference between string and character
✅ Relationship with `putchar()`
✅ Lightweight debugging output
✅ Embedded UART logging concept

---

# Summary

`puts()` is a simple C function designed for **printing strings efficiently**.

The key idea:

> `puts()` takes a string, sends each character to the output stream, and automatically adds a newline.

For embedded systems, understanding `puts()` helps you understand:

* UART debug messages
* String transmission
* Logging systems
* How higher-level functions are built from simple character operations

A strong C programmer should understand the relationship:

```
printf()
   |
   v
putchar()

puts()
   |
   v
putchar()
```

`putchar()` is the character-level output, while `puts()` is the string-level output.
