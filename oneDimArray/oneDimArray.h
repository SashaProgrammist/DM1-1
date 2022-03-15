#ifndef INC_1_1_ONEDIMARRAY_H
#define INC_1_1_ONEDIMARRAY_H

#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <malloc.h>
#include <stdio.h>
#include <assert.h>

#define SWAP(a, b) swap(a, b, sizeof(*(a)))

#define ASSERT_BOOL(_bool) { \
    if (!_bool){             \
        fprintf(stderr, "File %s\n", __FILE__); \
    fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__ , __LINE__); \
    }                        \
}

int int_compare(const void *a, const void *b);

void simplifyOrderedArray(void *array,
                          size_t sizeElement,
                          size_t *sizeArray);

void swap(void *a, void *b, size_t size);

int binSearchElement(const int *array, size_t size, int element);

int getIndexFirstInArrayLargerNumber(const int *array, size_t size, int number);

void insertElementIntoArray(int *array, size_t *size, int element, size_t index);

int pop(int *array, size_t *size, size_t index);

void printArray(int *array, size_t size);

int getMax(const int *array, size_t size);

void outputBoolArray(FILE *__stream, size_t size, bool *array);

#endif //INC_1_1_ONEDIMARRAY_H
