**Duca Andrei-Rares**

This project contains the implementation of a standard C library for Linux systems.

# Features

## String Management Functions:

Implemented functions such as strcpy(), strcat(), strlen(), strncpy(), strncat(), strcmp(), strncmp(), strstr(), strrstr(), memcpy(), memset(), memmove(), and memcmp() to facilitate basic string handling operations.

## Basic Memory Support:

Implemented malloc(), calloc(), realloc(), realloc_array(), free(), mmap(), mremap(), and munmap() for dynamic memory allocation and management.

## POSIX File I/O:

Supported file system operations through the implementation of open(), close(), lseek(), stat(), fstat(), truncate(), ftruncate().

## I/O and Time Functions:

Implemented the puts() function for basic I/O and nanosleep() and sleep() functions for time management.

## Syscall-Based Architecture:

All functions interact with the Linux kernel via direct system calls using syscall() without relying on external library calls.