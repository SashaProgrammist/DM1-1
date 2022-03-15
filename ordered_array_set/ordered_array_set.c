#include "ordered_array_set.h"

ordered_array_set ordered_array_set_create(size_t capacity) {
    int *data = (int *) malloc(capacity * sizeof(int));

    assert(data != NULL);

    return (ordered_array_set) {data, 0, capacity};
}

ordered_array_set ordered_array_set_create_from_array(const int *a,
                                                      size_t size) {
    ordered_array_set result =
            ordered_array_set_create(size);
    memcpy(result.data, a, size * sizeof(int));
    qsort(result.data, size,
          sizeof(int), int_compare);

    simplifyOrderedArray(result.data,
                         sizeof(int),
                         &size);
    result.size = size;

    return result;
}

size_t ordered_array_set_in(ordered_array_set set, int value) {
    size_t result = binSearchElement(set.data, set.size, value);

    if (result != -1)
        return result;
    else
        return set.capacity;
}

bool ordered_array_set_isEqual(ordered_array_set set1,
                               ordered_array_set set2) {
    if (set1.size != set2.size)
        return false;

    for (size_t i = 0; i < set1.size; i++)
        if (set1.data[i] != set2.data[i])
            return false;

    return true;
}

bool ordered_array_set_isSubset(ordered_array_set subset,
                                ordered_array_set set) {
    int *dataSet = set.data;
    int *dataSub = subset.data;

    size_t ireadSub = 0;
    for (size_t ireadSet = 0; ireadSet < set.size; ireadSet++) {
        if (dataSet[ireadSet] == dataSub[ireadSub]) {
            ireadSub++;
            if (ireadSub == subset.size)
                return true;
        }
    }

    return false;
}

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size != set->capacity);
}

void ordered_array_set_insert(ordered_array_set *set, int value) {

    int indexInsert = getIndexFirstInArrayLargerNumber(
            set->data, set->size, value - 1);

    if (set->size == indexInsert ||
        set->data[indexInsert] != value) {
        ordered_array_set_isAbleAppend(set);
        insertElementIntoArray(
                set->data, &set->size, value, indexInsert);
    }
}

void ordered_array_set_deleteElement(ordered_array_set *set,
                                     int value) {
    int indexDelete = getIndexFirstInArrayLargerNumber(
            set->data, set->size, value - 1);

    if (set->data[indexDelete] == value)
        pop(set->data, &set->size, indexDelete);
}

ordered_array_set ordered_array_set_union(ordered_array_set set1,
                                          ordered_array_set set2) {
    ordered_array_set result =
            ordered_array_set_create(set1.size + set2.size);

    size_t iread1 = 0;
    size_t iread2 = 0;

    while (iread1 < set1.size || iread2 < set2.size) {
        if (iread2 == set2.size ||
            (iread1 != set1.size &&
             set1.data[iread1] < set2.data[iread2])) {
            result.data[result.size] = set1.data[iread1];
            iread1++;
            result.size++;
        } else if (iread1 != set1.size &&
                   set1.data[iread1] == set2.data[iread2]) {
            result.data[result.size] = set1.data[iread1];
            iread1++;
            iread2++;
            result.size++;
        } else {
            result.data[result.size] = set2.data[iread2];
            iread2++;
            result.size++;
        }
    }

    return result;
}

ordered_array_set ordered_array_set_intersection(
        ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set result =
            ordered_array_set_create(min(set1.size, set2.size));

    size_t iread1 = 0;
    size_t iread2 = 0;

    while (iread1 < set1.size && iread2 < set2.size) {
        switch (int_compare(&set1.data[iread1], &set2.data[iread2])) {
            case 1:
                iread2++;
                break;
            case 0:
                result.data[result.size] = set1.data[iread1];
                iread1++;
                iread2++;
                result.size++;
                break;
            case -1:
                iread1++;
                break;
        }
    }

    return result;
}

ordered_array_set ordered_array_set_difference(
        ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set result =
            ordered_array_set_create(set1.size);

    size_t iread1 = 0;
    size_t iread2 = 0;

    while (iread1 < set1.size || iread2 < set2.size) {
        if (iread2 == set2.size ||
            (iread1 != set1.size &&
             set1.data[iread1] < set2.data[iread2])) {
            result.data[result.size] = set1.data[iread1];
            iread1++;
            result.size++;
        } else if (iread1 != set1.size &&
                   set1.data[iread1] == set2.data[iread2]) {
            iread1++;
            iread2++;
        } else {
            iread2++;
        }
    }

    return result;
}

ordered_array_set ordered_array_set_symmetricDifference(
        ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set result1 =
            ordered_array_set_difference(set1, set2);
    ordered_array_set result2 =
            ordered_array_set_difference(set2, set1);

    return ordered_array_set_union(result1, result2);
}

ordered_array_set ordered_array_set_complement(
        ordered_array_set set, ordered_array_set universumSet) {
    return ordered_array_set_difference(universumSet, set);
}

void ordered_array_set_print(ordered_array_set set) {
    printArray(set.data, set.size);
}

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}
