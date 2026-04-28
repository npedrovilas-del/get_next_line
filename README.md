*This project has been created as part of the 42 curriculum by pneto-vi.*

# Get_Next_Line

This project involves creating a function that allows reading an entire line from a file descriptor, one line at a time. It serves as a fundamental introduction to the use of static variables in C and efficient memory management during input operations.
Description

The get_next_line function reads content from a file and returns a single line per call. A line is defined as a sequence of characters ending with a newline (\n) or the end of the file.

# Parameter	Description
fd	The file descriptor to read from.
Return Value	The line read (including the newline character if present) or NULL if an error occurs or the end of the file is reached.

# Logical Workflow

    Read the file into a temporary buffer.

    Append the buffer content to a static variable that stores the accumulated data.

    Search for a newline character within the accumulated string.

    Extract the line up to the newline to be returned.

    Update the static variable to retain only the data following the extracted line.

# Usage

To integrate the function into a project, include the source files and define the buffer size during compilation.
Compilation

Example using a buffer size of 32:
Bash

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c

# Files Structure

    get_next_line.c: Contains the primary logic for the function.

    get_next_line_utils.c: Contains helper functions required for string manipulation (e.g., length calculation, joining, and searching).

    get_next_line.h: The header file containing function prototypes and necessary includes.

# Resources

Visual Learning: I utilized YouTube tutorials to visualize how the read() and open() functions operate at a system level, specifically how the file pointer moves during execution.

Research: I used technical forums such as GeeksforGeeks to clarify C syntax and AI tools to help structure the documentation for better readability.