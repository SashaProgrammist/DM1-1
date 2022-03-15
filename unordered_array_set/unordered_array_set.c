#include "unordered_array_set.h"

unordered_array_set unordered_array_set_create(size_t capacity) {
    int *data = (int *)malloc(capacity * sizeof(int));

    assert(data != NULL);

    return (unordered_array_set) { data, 0, capacity };
}

unordered_array_set unordered_array_set_create_from_array(
    const int *a, size_t size) {

    unordered_array_set resultSet =
        unordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        unordered_array_set_insert(&resultSet, a[i]);

    return resultSet;
}

size_t unordered_array_set_in(unordered_array_set set, int value) {
    for (size_t i = 0; i < set.size; i++)
        if (set.data[i] == value)
            return i;

    return set.capacity;
}

bool unordered_array_set_isEqual(unordered_array_set set1,
                                 unordered_array_set set2) {
    if (set1.size != set2.size)
        return false;

    for (size_t i = 0; i < set1.size; i++)
        if (unordered_array_set_in(set2, set1.data[i]) ==
            set2.capacity)
            return false;

    return true;
}

bool unordered_array_set_isSubset(unordered_array_set subset,
                                  unordered_array_set set) {
    if (subset.size > set.size)
        return false;

    for (size_t i = 0; i < subset.size; i++)
        if (unordered_array_set_in(set, subset.data[i]) == set.capacity)
            return false;

    return true;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size + 1 <= set->capacity);
}

void unordered_array_set_insert(unordered_array_set *set,
                                int value) {
    if (unordered_array_set_in(*set, value) == set->capacity){
        unordered_array_set_isAbleAppend(set);

        set->data[set->size] = value;
        set->size++;
    }
}

void unordered_array_set_deleteElement(
    unordered_array_set *set, int value) {
    size_t iValue = unordered_array_set_in(*set, value);

    if (iValue != set->capacity) {
        set->data[iValue] = set->data[set->size - 1];
        set->size--;
    }
}

unordered_array_set unordered_array_set_union(
        unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_cpy(set1);

    unordered_array_set_expand(&result, set2.size);

    for (size_t i = 0; i < set2.size; i++)
        unordered_array_set_insert(&result, set2.data[i]);

    return result;
}

unordered_array_set unordered_array_set_intersection(
    unordered_array_set set1, unordered_array_set set2){
    size_t resultSize = min(set1.size, set2.size);
    unordered_array_set result =
        unordered_array_set_create(resultSize);

    for (size_t i = 0; i < set1.size; i++)
        if (unordered_array_set_in(set2, set1.data[i]) !=
            set2.capacity)
            unordered_array_set_insert(&result, set1.data[i]);
    return result;
}

unordered_array_set unordered_array_set_difference(
    unordered_array_set set1, unordered_array_set set2) {
    return unordered_array_set_intersection(
        set1, unordered_array_set_complement(set2, set1));
}

unordered_array_set unordered_array_set_symmetricDifference(
    unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result1 =
        unordered_array_set_difference(set1, set2);
    unordered_array_set result2 =
        unordered_array_set_difference(set2, set1);

    return unordered_array_set_union(result1, result2);
}

unordered_array_set unordered_array_set_complement(
    unordered_array_set set, unordered_array_set universumSet) {
    unordered_array_set result =
        unordered_array_set_cpy(universumSet);

    for (size_t i = 0; i < set.size; i++)
        unordered_array_set_deleteElement(&result, set.data[i]);
    return result;
}

void unordered_array_set_print(unordered_array_set set){
    for (size_t i = 0; i < set.size; i++)
        printf("%d ", set.data[i]);
}

unordered_array_set unordered_array_set_cpy(
    unordered_array_set set) {

    int *data = (int *)malloc(sizeof(int) * set.size);
    unordered_array_set result =
        (unordered_array_set){ data, set.size, set.capacity };
    memcpy(result.data, set.data, sizeof(int) * set.size);

    return result;
}

void unordered_array_set_expand(
    unordered_array_set *set, size_t add) {
    int *t =  (int *)realloc(set->data,
                             (set->size + add) * sizeof(int));
    assert(t != NULL);
    set->data = t;
    set->capacity = set->size + add;
}
void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}
