#include "bitset.h"

unsigned getUniverse(const unsigned maxValue) {
    return (1 << (maxValue + 1)) - 1;
}

bitset bitset_create(unsigned maxValue) {
    assert(maxValue <= MAX_MAX_VALUE);
    return (bitset) { 0, maxValue };
}

bool bitset_in(bitset set, const unsigned value) {
    assert(value <= set.maxValue);
    return set.values & (1 << value);
}

bool bitset_isEqual(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return !((set1.values ^ set2.values) &
             getUniverse(set1.maxValue));
}

bool bitset_isSubset(bitset subset, bitset set) {
    assert(subset.maxValue == set.maxValue);
    return bitset_isEqual(bitset_intersection(subset, set),
                          subset);
}

void bitset_insert(bitset *set, const unsigned value) {
    assert(value <= set->maxValue);
    set->values |= 1 << value;
}

void bitset_deleteElement(bitset *set, const unsigned value) {
    assert(value <= set->maxValue);
    set->values &= ~(1 << value);
}

bitset bitset_union(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) { set1.values | set2.values, set1.maxValue };
}

bitset bitset_intersection(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) { set1.values & set2.values, set1.maxValue };
}

bitset bitset_difference(bitset set1, bitset set2) {
    return bitset_intersection(set1, bitset_complement(set2));
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) { set1.values ^ set2.values, set1.maxValue };
}

bitset bitset_complement(bitset set) {
    return (bitset) { ~set.values & getUniverse(set.maxValue),
                      set.maxValue };
}

void bitset_print(bitset set) {
    if (set.values & getUniverse(set.maxValue)) {
        printf("{ ");
        for (size_t i = 0; i <= set.maxValue; i++)
            if (set.values & (1 << i))
                printf("%u, ", i);
        printf("\b\b }");
    } else
        printf("{ }");
}
