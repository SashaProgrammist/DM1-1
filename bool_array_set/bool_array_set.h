#ifndef INC_1_1_BOOL_ARRAY_SET_H
#define INC_1_1_BOOL_ARRAY_SET_H

#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>

#include "../oneDimArray/oneDimArray.h"

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a < b ? b : a)

#define getBytSize(maxElem) (maxElem + 1) * sizeof(bool)

typedef struct bool_array_set {
    bool *data;
    size_t maxElem;
} bool_array_set;

#define ASSERT_BOOL_SET(result, set) assertBoolSet(result, \
                                      sizeof(result) / sizeof(bool), \
                                      set, \
                                      __FILE__, __FUNCTION__, __LINE__ )
void assertBoolSet(bool *expected, size_t expectedSize,
                   bool_array_set got,
                   char const *fileName, char const *funcName,
                   int line);

// возвращает пустое множество,
// с универсумом {0,1,...,maxElem}
bool_array_set bool_array_set_create(size_t maxElem);

// возвращает множество, состоящее
// из элементов массива a размера size
bool_array_set bool_array_set_create_from_array(const int *a,
                                                size_t size);

// возвращает есть ли value в множестве set
bool bool_array_set_in(bool_array_set set, int value);

// возвращает значение ’истина’,
// если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool bool_array_set_isEqual(bool_array_set set1,
                            bool_array_set set2);

bool bool_array_set_isNull(bool_array_set set);

// возвращает значение ’истина’,
// если subset является подмножеством set
// иначе - ’ложь’
bool bool_array_set_isSubset(bool_array_set subset,
                             bool_array_set set);

// добавляет элемент value в множество set
void bool_array_set_insert(bool_array_set set, int value);

// удаляет элемент value из множества set
void bool_array_set_deleteElement(bool_array_set set,
                                  int value);

// возвращает объединение множеств set1 и set2
bool_array_set bool_array_set_union(bool_array_set set1,
                                    bool_array_set set2);

// возвращает пересечение множеств set1 и set2
bool_array_set bool_array_set_intersection(
        bool_array_set set1, bool_array_set set2);

// возвращает разность множеств set1 и set2
bool_array_set bool_array_set_difference(bool_array_set set1,
                                         bool_array_set set2);

// возвращает симметрическую разность множеств set1 и set2
bool_array_set bool_array_set_symmetricDifference(
        bool_array_set set1, bool_array_set set2);

// возвращает дополнение до универсума множества set
bool_array_set bool_array_set_complement(bool_array_set set, bool_array_set universe);

// вывод множества set
void bool_array_set_print(bool_array_set set);

// освобождает память, занимаемую множеством set
void bool_array_set_delete(bool_array_set set);

#endif //INC_1_1_BOOL_ARRAY_SET_H
