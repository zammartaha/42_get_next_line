*This project has been created as part of the 42 curriculum by tzammar.*

# Libft - Your First C Library

## Description

**Libft** is the very first project at 42. The goal of this project is to create a C library (`libft.a`) from scratch.

As C programmers, we do not have access to a standard library with the same ease as in other languages. This project requires replicating many of the standard C library functions (from headers like `stdio.h`, `string.h`, `ctype.h`, and `stdlib.h`) as well as creating additional utility functions that will be useful for future 42 projects.

The project emphasizes understanding memory management, string manipulation, and linked lists, serving as a foundational toolkit for the entire curriculum.

## Instructions

### Usage
To use this function in your own code:

Include the header file:

```C
#include "get_next_line.h"
```
Call the function in a loop to read a file line by line:

```C
int		fd;
char	*line;

fd = open("file.txt", O_RDONLY);
line = get_next_line(fd)
while (line)
{
	printf("%s", line);
	free(line);
	line = get_next_line(fd)
}
```
## Features
* **Reads Line-by-Line:** correctly handles files with variable line lengths.
* **Buffer Management:** Uses a customizable BUFFER_SIZE to read chunks of data from the file descriptor.
* **Static Variables:** effectively uses static variables to store "leftover" characters from the buffer for the next function call.
* **Memory Management:** Ensures no memory leaks occur during the reading process (all allocated lines must be freed by the caller).
* **Bonus:** Handles multiple file descriptors simultaneously using a single static variable (e.g., reading from fd 3, then fd 4, then back to fd 3 without losing position).

## Resources

### References
* **Man7.org - Read** - Manual page for the read system call. https://man7.org/linux/man-pages/man2/read.2.html
* **Man7.org - Open** - Manual page for opening files/file descriptors. https://man7.org/linux/man-pages/man2/open.2.html
* **GeeksforGeeks - Static Variables in C** - Explanation of static variables. https://www.geeksforgeeks.org/c/static-variables-in-c/