// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	while (len > 0 && *source != '\0') {
        *destination = *source;
        destination++;
        source++;
        len--;
    }

    while (len > 0) {
        *destination = '\0';
        destination++;
        len--;
    }

	return destination;
}

char *strcat(char *destination, const char *source)
{
	while (*destination != '\0') {
        destination++;
    }

    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	while (*destination != '\0') {
        destination++;
    }

    while (len > 0 && *source != '\0') {
        *destination = *source;
        destination++;
        source++;
        len--;
    }

    *destination = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2) {
        if (*str1 == '\0') {
            return 0;
        }
        str1++;
        str2++;
    }

    return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	while (len > 0 && *str1 == *str2) {
		if (*str1 == '\0') {
        	return 0;
        }

		str1++;
        str2++;
        len--;
    }

	if (!len)
		return 0;

	return *str1 - *str2;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }

	return NULL;
}

char *strrchr(const char *str, int c)
{
	const char *last = NULL;

    while (*str != '\0') {
        if (*str == c) {
            last = str;
        }
        str++;
    }

    return (char *)last;
}

char *strstr(const char *haystack, const char *needle)
{
	size_t needle_len = strlen(needle);

    while (*haystack != '\0') {
        if (strncmp(haystack, needle, needle_len) == 0) {
            return (char *)haystack;
        }
        haystack++;
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	const char *last = NULL;
    size_t needle_len = strlen(needle);

    while (*haystack != '\0') {
        if (strncmp(haystack, needle, needle_len) == 0) {
            last = haystack;
        }
        haystack++;
    }

    return (char *)last;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *dest_copy = (char *)destination;
    const char *source_copy = (const char *)source;

    while (num > 0) {
        *dest_copy = *source_copy;
        dest_copy++;
        source_copy++;
        num--;
    }

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *csrc = (char *)source;
	char *cdest = (char *)destination;

	char temp[num];

	for (size_t i = 0; i < num; i++)
    	temp[i] = csrc[i];

	for (size_t i = 0; i < num; i++)
    	cdest[i] = temp[i];

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;

    while (num > 0) {
        if (*p1 != *p2) {
            return *p1 - *p2;
        }
        p1++;
        p2++;
        num--;
    }

    return 0;
}

void *memset(void *source, int value, size_t num)
{
	unsigned char *source_copy = (unsigned char *)source;

    while (num > 0) {
        *source_copy = (unsigned char)value;
        source_copy++;
        num--;
    }

	return source;
}
