# `getchar()` Function in C Programming

## 1. Introduction

`getchar()` is a standard input function in C used to **read a single character from the standard input device** (usually the keyboard).

The name means:

> **get character**

It is part of the C Standard Input/Output library:

```c
#include <stdio.h>
```

Unlike `scanf()`, which reads formatted data, `getchar()` simply reads **one character at a time**.

---

# 2. Basic Syntax

```c
character_variable = getchar();
```

Example:

```c
#include <stdio.h>

int main()
{
    char ch;

    printf("Enter a character: ");

    ch = getchar();

    printf("You entered: %c", ch);

    return 0;
}
```

### Output:

```
Enter a character: A
You entered: A
```

---

# 3. How `getchar()` Works Internally

When you press a key:

```
Keyboard
    |
    |
    v
Input Buffer
    |
    |
    v
getchar()
    |
    |
    v
Character Variable
```

Example:

User enters:

```
R
```

Memory:

```
ch = 'R'
```

---

# 4. Return Value of `getchar()`

`getchar()` returns the character read as an integer.

Function prototype:

```c
int getchar(void);
```

Why does it return `int` instead of `char`?

Because it needs to represent:

* All possible characters
* Special value `EOF` (End Of File)

Example:

```c
#include <stdio.h>

int main()
{
    int ch;

    ch = getchar();

    printf("ASCII value = %d", ch);

    return 0;
}
```

Input:

```
A
```

Output:

```
ASCII value = 65
```

Because:

```
'A' = ASCII 65
```

---

# 5. Reading a Character

Example:

```c
#include <stdio.h>

int main()
{
    char grade;

    printf("Enter grade: ");

    grade = getchar();

    printf("Grade = %c", grade);

    return 0;
}
```

Input:

```
B
```

Output:

```
Grade = B
```

---

# 6. Reading Multiple Characters

`getchar()` reads only one character each time.

Example:

```c
#include <stdio.h>

int main()
{
    char a;
    char b;

    a = getchar();
    b = getchar();

    printf("%c\n",a);
    printf("%c\n",b);

    return 0;
}
```

Input:

```
AB
```

Output:

```
A
B
```

---

# 7. Reading a Complete String Using `getchar()`

A string can be read character by character.

Example:

```c
#include <stdio.h>

int main()
{
    char name[20];

    int i = 0;

    char ch;

    while((ch = getchar()) != '\n')
    {
        name[i] = ch;
        i++;
    }

    name[i] = '\0';

    printf("Name: %s", name);

    return 0;
}
```

Input:

```
Rajib
```

Output:

```
Name: Rajib
```

---

# 8. Understanding the Input Buffer

One of the most important concepts.

When you type:

```
A + Enter
```

The keyboard buffer contains:

```
'A' '\n'
```

Example:

```c
char ch1;
char ch2;

ch1 = getchar();
ch2 = getchar();
```

Input:

```
A
```

The values become:

```
ch1 = 'A'
ch2 = '\n'
```

Because Enter key also creates a character.

---

# 9. Problem with `scanf()` and `getchar()`

Common beginner problem:

```c
#include <stdio.h>

int main()
{
    int age;
    char grade;

    printf("Enter age: ");
    scanf("%d",&age);

    printf("Enter grade: ");
    grade = getchar();

    printf("Grade = %c",grade);

    return 0;
}
```

Input:

```
25
A
```

Expected:

```
Grade = A
```

Actual:

```
Grade = 

```

Why?

Because after entering:

```
25 + Enter
```

The buffer contains:

```
25\n
```

`scanf()` reads:

```
25
```

but leaves:

```
\n
```

Then `getchar()` reads that newline.

---

# 10. Solution: Clear Input Buffer

Method 1:

```c
while(getchar() != '\n');
```

Example:

```c
#include <stdio.h>

int main()
{
    int age;
    char grade;

    scanf("%d",&age);

    while(getchar() != '\n');

    grade = getchar();

    printf("%c",grade);

    return 0;
}
```

---

# 11. `getchar()` vs `scanf()`

| Feature      | getchar()        | scanf()                 |
| ------------ | ---------------- | ----------------------- |
| Reads        | Single character | Formatted data          |
| Header       | stdio.h          | stdio.h                 |
| Input type   | Character        | int, float, string, etc |
| Complexity   | Simple           | More complex            |
| Speed        | Faster           | Slower                  |
| Memory usage | Low              | Higher                  |

---

# 12. `getchar()` vs `getch()`

Many beginners confuse them.

| getchar()            | getch()                |
| -------------------- | ---------------------- |
| Standard C function  | Non-standard function  |
| Requires Enter key   | Reads immediately      |
| Available everywhere | Mostly Windows console |
| Uses `<stdio.h>`     | Uses `<conio.h>`       |

Example:

`getchar()`:

```
Press A + Enter
```

`getch()`:

```
Press A
(immediately captured)
```

---

# 13. Using `getchar()` for Menu Systems

Example:

```c
#include <stdio.h>

int main()
{
    char choice;

    printf("Menu\n");
    printf("A. Start\n");
    printf("B. Stop\n");

    printf("Select: ");

    choice = getchar();

    if(choice == 'A')
    {
        printf("Starting...");
    }
    else if(choice == 'B')
    {
        printf("Stopping...");
    }

    return 0;
}
```

---

# 14. Using `getchar()` for Character Counting

Example:

Count characters until Enter:

```c
#include <stdio.h>

int main()
{
    char ch;
    int count = 0;

    while((ch=getchar())!='\n')
    {
        count++;
    }

    printf("Characters = %d",count);

    return 0;
}
```

Input:

```
Embedded
```

Output:

```
Characters = 8
```

---

# 15. Using `getchar()` with EOF

EOF means:

> End Of File

Example:

```c
#include <stdio.h>

int main()
{
    int ch;

    while((ch=getchar()) != EOF)
    {
        putchar(ch);
    }

    return 0;
}
```

This program copies input to output.

---

# 16. `getchar()` and ASCII

Characters are stored as numbers.

Example:

```c
char ch='A';

printf("%d",ch);
```

Output:

```
65
```

Using:

```c
ch=getchar();
```

You can process ASCII values.

Example:

```c
char ch;

ch=getchar();

printf("ASCII=%d",ch);
```

Input:

```
a
```

Output:

```
ASCII=97
```

---

# 17. `getchar()` in Embedded Systems

In embedded systems:

* STM32
* ESP32
* AVR
* PIC

there is usually no keyboard.

But `getchar()` can be redirected to:

* UART
* USB CDC
* Serial terminal

Architecture:

```
PC Terminal
      |
      |
    UART
      |
      |
   getchar()
      |
      |
 MCU Variable
```

Example:

PC sends:

```
100
```

MCU receives characters:

```
'1'
'0'
'0'
```

Then firmware converts them into:

```
100
```

---

# 18. Embedded Example Concept

Normal C:

```c
char command;

command = getchar();

if(command == 'S')
{
    Motor_Start();
}
```

UART command:

```
S
```

Result:

```
Motor starts
```

---

# 19. Advantages of `getchar()`

✅ Very simple
✅ Low memory usage
✅ Character-level control
✅ Useful for parsing data
✅ Good for embedded communication
✅ Helps understand buffers

---

# 20. Limitations of `getchar()`

❌ Reads only one character
❌ Requires buffer handling
❌ Not suitable for complex input alone
❌ Needs conversion for numbers

Example:

Input:

```
123
```

`getchar()` receives:

```
'1'
'2'
'3'
```

You need manual conversion:

```
"123" → 123
```

---

# 21. Comparison of C Input Functions

| Function    | Purpose                        |
| ----------- | ------------------------------ |
| `scanf()`   | Formatted input                |
| `getchar()` | Single character input         |
| `gets()`    | String input (unsafe, removed) |
| `fgets()`   | Safe string input              |
| `getc()`    | Character from stream          |

---

# 22. Key Learning Points

After learning `getchar()` you should understand:

✅ Character input
✅ ASCII concept
✅ Input buffer
✅ Newline character
✅ EOF handling
✅ Character parsing
✅ UART input concept

---

# Summary

`getchar()` is a simple but powerful C function that teaches the foundation of **character handling and input streams**.

For beginners, it builds understanding of:

* How computers store characters
* How keyboards communicate with programs
* How buffers work
* How embedded systems receive serial data

For embedded firmware development, the concept behind `getchar()` is very important because UART communication is essentially **receiving and processing characters from a data stream**.
