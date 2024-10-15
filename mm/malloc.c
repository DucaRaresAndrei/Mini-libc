// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (ptr == MAP_FAILED) {
        return NULL;
    }

    mem_list_add(ptr, size);

    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
    void *ptr = malloc(total_size);

    if (ptr) {
        memset(ptr, 0, total_size);
    }

    return ptr;
}

void free(void *ptr)
{
	struct mem_list *item = mem_list_find(ptr);

    if (item != NULL && item->start != NULL) {
		munmap(item->start, item->len);
        mem_list_del(item->start);
    }
}

void *realloc(void *ptr, size_t size)
{
	void *new_ptr = malloc(size);

    if (new_ptr) {
        size_t old_size = sizeof(ptr);
        if (old_size < size) {
            memcpy(new_ptr, ptr, old_size);
        } else {
            memcpy(new_ptr, ptr, size);
        }

        free(ptr);
    }

    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
    return realloc(ptr, total_size);
}
