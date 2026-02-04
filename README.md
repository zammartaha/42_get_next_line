*This project has been created as part of the 42 curriculum by tzammar.*

# Get Next Line - Reading a line from a file descriptor is way too tedious.

## Description

**Get Next Line** is a project at 42 that challenges you to write a function that reads a line from a file descriptor.

Reading from a file one line at a time is a common task in programming, but the standard C library doesn't provide a simple function to do this without standard I/O streams. This project requires manipulating file descriptors, managing buffers, and utilizing **static variables** to preserve the state of the file reading between function calls.

The core objective is to create a function `get_next_line` which returns a line read from a file descriptor, or `NULL` if there is nothing else to read or an error occurred.

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
* **[Man7.org - Read](https://man7.org/linux/man-pages/man2/read.2.html)** - Manual page for the read system call.
* **[Man7.org - Open](https://man7.org/linux/man-pages/man2/open.2.html)** - Manual page for opening files/file descriptors.
* **[GeeksforGeeks - Static Variables in C](https://www.geeksforgeeks.org/c/static-variables-in-c/)** - Explanation of static variables.
