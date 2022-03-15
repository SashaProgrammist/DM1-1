#include "bool_array_set.h"

bool_array_set bool_array_set_create(size_t maxElem) {
    bool_array_set result;
    result.data = calloc((maxElem + 1), sizeof(bool));
    result.maxElem = maxElem;
    return result;
}

bool_array_set bool_array_set_create_from_array(const int *a, size_t size) {
    if (size == 0) {
        return bool_array_set_create(0);
    }

    int maxElem = getMax(a, size);

    bool_array_set result = bool_array_set_create(maxElem);

    for (int i = 0; i < size; ++i)
        bool_array_set_insert(result, a[i]);

    return result;
}

void bool_array_set_insert(bool_array_set set, int value) {
    if (value < 0 || value > set.maxElem)
        exit(1);

    set.data[value] = true;
}

bool bool_array_set_in(bool_array_set set, int value) {
    if (value < 0 || value > set.maxElem)
        return false;

    return set.data[value];
}

bool bool_array_set_isEqual(bool_array_set set1, bool_array_set set2) {
    int i = 0;
    int j = 0;

    while (i <= set1.maxElem &&
           j <= set2.maxElem) {
        if (set1.data[i] != set2.data[j])
            return false;
        i++;
        j++;
    }

    for (; i <= set1.maxElem; ++i)
        if (set1.data[i])
            return false;

    for (; j <= set2.maxElem; ++j)
        if (set1.data[j])
            return false;

    return true;
}

bool bool_array_set_isSubset(bool_array_set subset, bool_array_set set) {
    if (subset.maxElem > set.maxElem)
        return false;

    for (int i = 0; i <= subset.maxElem; ++i)
        if (subset.data[i] && !set.data[i])
            return false;

    return true;
}

void bool_array_set_deleteElement(bool_array_set set, int value) {
    if (value < 0 || value > set.maxElem)
        exit(1);

    set.data[value] = false;
}

bool_array_set bool_array_set_union(bool_array_set set1, bool_array_set set2) {
    size_t maxElem;
    bool_array_set lesSet, larSet;
    if (set1.maxElem > set2.maxElem) {
        maxElem = set1.maxElem;
        lesSet = set2;
        larSet = set1;
    } else {
        maxElem = set2.maxElem;
        lesSet = set1;
        larSet = set2;
    }

    bool_array_set result = bool_array_set_create(maxElem);

    memcpy(result.data,
           larSet.data,
           (maxElem + 1) * sizeof(bool));

    for (int i = 0; i <= lesSet.maxElem; ++i)
        if (lesSet.data[i])
            result.data[i] = true;

    return result;
}

bool_array_set bool_array_set_intersection(bool_array_set set1, bool_array_set set2) {
    size_t maxElem = min(set1.maxElem, set2.maxElem);

    bool_array_set result = bool_array_set_create(maxElem);

    for (int i = 0; i <= maxElem; ++i)
        result.data[i] = set1.data[i] && set2.data[i];

    return result;
}

bool_array_set bool_array_set_difference(bool_array_set set1, bool_array_set set2) {
    size_t maxElem = set1.maxElem;

    bool_array_set result = bool_array_set_create(maxElem);

    if (set2.maxElem <= maxElem) {
        memcpy(result.data,
               set1.data,
               (maxElem + 1) * sizeof(bool));

        for (int i = 0; i <= set2.maxElem; ++i)
            if (set2.data[i])
                result.data[i] = false;
    } else
        for (int i = 0; i <= maxElem; ++i)
            result.data[i] = set1.data[i] && !set2.data[i];

    return result;
}

bool_array_set bool_array_set_symmetricDifference(bool_array_set set1, bool_array_set set2) {
    size_t maxElem;
    bool_array_set lesSet, larSet;
    if (set1.maxElem > set2.maxElem) {
        maxElem = set1.maxElem;
        lesSet = set2;
        larSet = set1;
    } else {
        maxElem = set2.maxElem;
        lesSet = set1;
        larSet = set2;
    }

    bool_array_set result = bool_array_set_create(maxElem);

    memcpy(result.data,
           larSet.data,
           (maxElem + 1) * sizeof(bool));

    for (int i = 0; i <= lesSet.maxElem; ++i)
        result.data[i] ^= lesSet.data[i];

    return result;
}

bool_array_set bool_array_set_complement(bool_array_set set, bool_array_set universe) {
    bool_array_set result = bool_array_set_create(universe.maxElem);

    for (int i = 0; i <= universe.maxElem; ++i)
        result.data[i] = universe.data[i] && !bool_array_set_in(set, i);

    return result;
}

void bool_array_set_print(bool_array_set set) {
    if (bool_array_set_isNull(set)){
        printf("{ }");
        return;
    }

    printf("{ ");
    for (size_t i = 0; i <= set.maxElem; i++)
        if (set.data[i])
            printf("%u, ", i);
    printf("\b\b }");
}

void bool_array_set_delete(bool_array_set set) {
    free(set.data);
}

void assertBoolSet(bool *expected, size_t expectedSize,
                   bool_array_set got,
                   const char *fileName,
                   const char *funcName,
                   int line) {
    if (got.maxElem != expectedSize - 1 ||
        memcmp(got.data,
               expected,
               expectedSize * sizeof(bool)) != 0) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);

        fprintf(stderr, "Expected: ");
        outputBoolArray(stderr, expectedSize, expected);
        fprintf(stderr, "\n");

        fprintf(stderr, "Got:      ");
        outputBoolArray(stderr, got.maxElem + 1, got.data);
        fprintf(stderr, "\n");
    }
}

bool bool_array_set_isNull(bool_array_set set) {
    for (int i = 0; i <= set.maxElem; ++i)
        if (set.data[i])
            return false;

    return true;
}
