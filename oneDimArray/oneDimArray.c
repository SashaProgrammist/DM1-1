#include "oneDimArray.h"

void simplifyOrderedArray(void *array,
                          const size_t sizeElement,
                          size_t *sizeArray) {
    void *ptrRead = array + sizeElement;
    void *end = array + *sizeArray * sizeElement;

    while (ptrRead < end &&
           memcmp(ptrRead - sizeElement,
                  ptrRead,
                  sizeElement) != 0) {
        ptrRead += sizeElement;
    }

    void *ptrWrite = ptrRead;
    void *ptrRevise = ptrRead - sizeElement;
    ptrRead += sizeElement;

    while (ptrRead < end) {
        if (memcmp(ptrRevise,
                   ptrRead,
                   sizeElement) != 0) {
            memcpy(ptrWrite, ptrRead, sizeElement);
            ptrWrite += sizeElement;
            ptrRevise += sizeElement;
        }
        ptrRead += sizeElement;
    }

    *sizeArray = (ptrWrite - array) / sizeElement;
}

void swap(void *a, void *b, size_t size) {
    void *t = malloc(size);

    memcpy(t, a, size);
    memcpy(a, b, size);
    memcpy(b, t, size);

    free(t);
}

int int_compare(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int binSearchElement(const int *array, size_t size, int element) {
    int rightBorder = 0;
    int leftBorder = (int) size - 1;

    while (leftBorder >= rightBorder) {
        int middle = rightBorder + (leftBorder - rightBorder) / 2;

        int curentElement = array[middle];

        if (curentElement == element)
            return middle;

        if (curentElement > element)
            leftBorder = middle - 1;
        else
            rightBorder = middle + 1;
    }

    return -1;
}

int getIndexFirstInArrayLargerNumber(const int *array, size_t size, int number) {
    int rightBorder = -1;
    int leftBorder = (int) size;

    while (leftBorder - rightBorder > 1) {
        int medle = rightBorder + (leftBorder - rightBorder) / 2;

        if (array[medle] <= number)
            rightBorder = medle;
        else
            leftBorder = medle;
    }

    return leftBorder;
}

void insertElementIntoArray(int *array, size_t *size, int element, size_t index) {
    for (size_t i = *size; i > index; i--)
        array[i] = array[i - 1];

    array[index] = element;

    ++*size;
}

int pop(int *array, size_t *size, size_t index) {
    int popElement = array[index];

    for (size_t i = index + 1; i < *size; i++)
        array[i - 1] = array[i];

    --*size;

    return popElement;
}

void printArray(int *array, size_t size) {
    for (size_t i = 0; i < size; i++)
        printf("%d ", array[i]);

    printf("\n");
}

int getMax(const int *array, size_t size) {
    int result = *array;

    for (int i = 0; i < size; ++i)
        if (array[i] > result)
            result = array[i];

    return result;
}

void outputBoolArray(FILE *stream, size_t size, bool *array) {
    for (int i = 0; i < size; ++i)
        fprintf(stream,"%d ", array[i]);
}

