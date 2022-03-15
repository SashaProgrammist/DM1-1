#include"bitset/bitset.h"
#include"unordered_array_set/unordered_array_set.h"
#include"ordered_array_set/ordered_array_set.h"
#include "bool_array_set/bool_array_set.h"

void test_bitset_in1() {
    bitset set = (bitset) {10, 10}; // {1, 3}
    assert(!bitset_in(set, 5));
}

void test_bitset_in2() {
    bitset set = (bitset) {15, 10}; // {0, 1, 2, 3}
    assert(bitset_in(set, 2));
}

void test_bitset_in() {
    test_bitset_in1();
    test_bitset_in2();
}

void test_bitset_isSubset1() {
    bitset set1 = (bitset) {90, 10}; // {6, 4, 3, 1}
    bitset set2 = (bitset) {10, 10}; // {3, 1}

    assert(bitset_isSubset(set2, set1));
}

void test_bitset_isSubset2() {
    bitset set1 = (bitset) {90, 10}; // {6, 4, 3, 1}
    bitset set2 = (bitset) {11, 10}; // {3, 1, 0}

    assert(!bitset_isSubset(set2, set1));
}

void test_bitset_isSubset() {
    test_bitset_isSubset1();
    test_bitset_isSubset2();
}

void test_bitset_insert1() {
    bitset set = (bitset) {10, 10}; // {1, 3}
    bitset_insert(&set, 2);
    assert(set.values == 14);
}

void test_bitset_insert2() {
    bitset set = (bitset) {10, 10}; // {1, 3}
    bitset_insert(&set, 3);
    assert(set.values == 10);
}

void test_bitset_insert() {
    test_bitset_insert1();
    test_bitset_insert2();
}

void test_bitset_union1() {
    bitset set1 = (bitset) {90, 10}; // {6, 4, 3, 1}
    bitset set2 = (bitset) {5, 10}; // {2, 0}
    // r 95 {6, 4, 3, 2, 1, 0}
    assert(bitset_union(set1, set2).values == 95);
}

void test_bitset_union2() {
    bitset set1 = (bitset) {90, 10}; // {6, 4, 3, 1}
    bitset set2 = (bitset) {53, 10}; // {5, 4, 2, 0}
    // r 127 {6, 5, 4, 3, 2, 1, 0}
    assert(bitset_union(set1, set2).values == 127);
}

void test_bitset_union() {
    test_bitset_union1();
    test_bitset_union2();
}

void test_bitset_intersection1() {
    bitset set1 = (bitset) {90, 10}; // {6, 4, 3, 1}
    bitset set2 = (bitset) {53, 10}; // {5, 4, 2, 0}
    // r 16 {4}
    assert(bitset_intersection(set1, set2).values == 16);
}

void test_bitset_intersection2() {
    bitset set1 = (bitset) {74, 10}; // {6, 3, 1}
    bitset set2 = (bitset) {53, 10}; // {5, 4, 2, 0}
    // r 0 { }
    assert(bitset_intersection(set1, set2).values == 0);
}

void test_bitset_intersection() {
    test_bitset_intersection1();
    test_bitset_intersection2();
}

void test_bitset_difference1() {
    bitset set1 = (bitset) {90, 10}; // {6, 4, 3, 1}
    bitset set2 = (bitset) {53, 10}; // {5, 4, 2, 0}
    // r 74 {6, 3, 1}
    assert(bitset_difference(set1, set2).values == 74);
}

void test_bitset_difference2() {
    bitset set1 = (bitset) {74, 10}; // {6, 3, 1}
    bitset set2 = (bitset) {54, 10}; // {5, 4, 2, 1}
    // r 72 {6, 3}
    assert(bitset_difference(set1, set2).values == 72);
}

void test_bitset_difference() {
    test_bitset_difference1();
    test_bitset_difference2();
}

void test_bitset_symmetricDifference1() {
    bitset set1 = (bitset) {90, 10}; // {6, 4, 3, 1}
    bitset set2 = (bitset) {53, 10}; // {5, 4, 2, 0}
    // r 111 {6, 5, 3, 2, 1, 0}
    assert(bitset_symmetricDifference(set1, set2).values == 111);
}

void test_bitset_symmetricDifference2() {
    bitset set1 = (bitset) {74, 10}; // {6, 3, 1}
    bitset set2 = (bitset) {54, 10}; // {5, 4, 2, 1}
    // r 124 {6, 5, 4, 3, 2}
    assert(bitset_symmetricDifference(set1, set2).values == 124);
}

void test_bitset_symmetricDifference() {
    test_bitset_symmetricDifference1();
    test_bitset_symmetricDifference2();
}

void test_bitset_complement1() {
    bitset set = (bitset) {10, 6}; // {1, 3}
    // r 117 {6, 5, 4, 2, 0}
    assert(bitset_complement(set).values == 117);
}

void test_bitset_complement2() {
    bitset set = (bitset) {63, 10}; // {0, 1, 2, 3, 4, 5}
    // r 1984 {10, 9, 8, 7, 6}
    assert(bitset_complement(set).values == 1984);
}

void test_bitset_complement() {
    test_bitset_complement1();
    test_bitset_complement2();
}

void test_bitset() {
    test_bitset_in();
    test_bitset_isSubset();
    test_bitset_insert();
    test_bitset_union();
    test_bitset_intersection();
    test_bitset_difference();
    test_bitset_symmetricDifference();
    test_bitset_complement();
}

void test_unordered_array_set_in1() {
    unordered_array_set set =
            unordered_array_set_create_from_array(
                    (int[]) {2, 4}, 2);
    assert(unordered_array_set_in(set, 5) == 2);

    unordered_array_set_delete(set);
}

void test_unordered_array_set_in2() {
    unordered_array_set set =
            unordered_array_set_create_from_array(
                    (int[]) {4, 1, 3, 2}, 4);
    assert(unordered_array_set_in(set, 2) == 3);

    unordered_array_set_delete(set);
}

void test_unordered_array_set_in() {
    test_unordered_array_set_in1();
    test_unordered_array_set_in2();
}

void test_unordered_array_set_isSubset1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array(
                    (int[]) {3, 1}, 2);

    assert(unordered_array_set_isSubset(set2, set1));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_isSubset2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array(
                    (int[]) {3, 1, 0}, 3);

    assert(!unordered_array_set_isSubset(set2, set1));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_isSubset() {
    test_unordered_array_set_isSubset1();
    test_unordered_array_set_isSubset2();
}

void test_unordered_array_set_insert1() {
    unordered_array_set set = unordered_array_set_create(3);
    unordered_array_set_insert(&set, 2);
    unordered_array_set_insert(&set, 1);
    unordered_array_set_insert(&set, 3);
    unordered_array_set result =
            unordered_array_set_create_from_array(
                    (int[]) {1, 3, 2}, 3);
    assert(unordered_array_set_isEqual(set, result));

    unordered_array_set_delete(set);
    unordered_array_set_delete(result);
}

void test_unordered_array_set_insert2() {
    unordered_array_set set = unordered_array_set_create(3);
    unordered_array_set_insert(&set, 3);
    unordered_array_set_insert(&set, 1);
    unordered_array_set_insert(&set, 3);
    unordered_array_set result =
            unordered_array_set_create_from_array(
                    (int[]) {1, 3}, 2);
    assert(unordered_array_set_isEqual(set, result));

    unordered_array_set_delete(set);
    unordered_array_set_delete(result);
}

void test_unordered_array_set_insert() {
    test_unordered_array_set_insert1();
    test_unordered_array_set_insert2();
}

void test_unordered_array_set_union1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array(
                    (int[]) {0, 5}, 2);
    unordered_array_set result =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1, 0, 5}, 6);
    unordered_array_set expectedSet =
            unordered_array_set_union(set1, set2);
    assert(unordered_array_set_isEqual(expectedSet, result));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(result);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array(
                    (int[]) {0, 5, 4}, 3);
    unordered_array_set result =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1, 0, 5}, 6);
    unordered_array_set expectedSet =
            unordered_array_set_union(set1, set2);
    assert(unordered_array_set_isEqual(expectedSet, result));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(result);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union() {
    test_unordered_array_set_union1();
    test_unordered_array_set_union2();
}

void test_unordered_array_set_intersection1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array(
                    (int[]) {0, 5}, 2);
    unordered_array_set result =
            unordered_array_set_create(0);
    unordered_array_set expectedSet =
            unordered_array_set_intersection(set1, set2);
    assert(unordered_array_set_isEqual(expectedSet, result));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(result);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array(
                    (int[]) {0, 5, 4}, 3);
    unordered_array_set result =
            unordered_array_set_create_from_array(
                    (int[]) {4}, 1);
    unordered_array_set expectedSet =
            unordered_array_set_intersection(set1, set2);
    assert(unordered_array_set_isEqual(expectedSet, result));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(result);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection() {
    test_unordered_array_set_intersection1();
    test_unordered_array_set_intersection2();
}

void test_unordered_array_set_difference1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array(
                    (int[]) {0, 5}, 2);
    unordered_array_set result =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1}, 4);
    unordered_array_set expectedSet =
            unordered_array_set_difference(set1, set2);
    assert(unordered_array_set_isEqual(expectedSet, result));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(result);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array(
                    (int[]) {0, 5, 4}, 3);
    unordered_array_set result =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 1}, 3);
    unordered_array_set expectedSet =
            unordered_array_set_difference(set1, set2);
    assert(unordered_array_set_isEqual(expectedSet, result));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(result);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference() {
    test_unordered_array_set_difference1();
    test_unordered_array_set_difference2();
}

void test_unordered_array_set_symmetricDifference1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array(
                    (int[]) {0, 5}, 2);
    unordered_array_set result =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1, 0, 5}, 6);
    unordered_array_set expectedSet =
            unordered_array_set_symmetricDifference(set1, set2);
    assert(unordered_array_set_isEqual(expectedSet, result));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(result);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array(
                    (int[]) {0, 5, 4, 6}, 4);
    unordered_array_set result =
            unordered_array_set_create_from_array(
                    (int[]) {3, 1, 0, 5}, 4);
    unordered_array_set expectedSet =
            unordered_array_set_symmetricDifference(set1, set2);
    assert(unordered_array_set_isEqual(expectedSet, result));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(result);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference() {
    test_unordered_array_set_symmetricDifference1();
    test_unordered_array_set_symmetricDifference2();
}

void test_unordered_array_set() {
    test_unordered_array_set_in();
    test_unordered_array_set_isSubset();
    test_unordered_array_set_insert();
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_symmetricDifference();
}

void test_ordered_array_set_in1() {
    ordered_array_set set =
            ordered_array_set_create_from_array(
                    (int[]) {2, 4}, 2);
    assert(ordered_array_set_in(set, 5) == 2);

    ordered_array_set_delete(set);
}

void test_ordered_array_set_in2() {
    ordered_array_set set =
            ordered_array_set_create_from_array(
                    (int[]) {1, 2, 3, 4}, 4);
    assert(ordered_array_set_in(set, 2) == 1);

    ordered_array_set_delete(set);
}

void test_ordered_array_set_in() {
    test_ordered_array_set_in1();
    test_ordered_array_set_in2();
}

void test_ordered_array_set_isSubset1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array(
                    (int[]) {6, 4, 3, 1}, 4);
    ordered_array_set set2 =
            ordered_array_set_create_from_array(
                    (int[]) {3, 1}, 2);

    assert(ordered_array_set_isSubset(set2, set1));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
}

void test_ordered_array_set_isSubset2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array(
                    (int[]) {6, 4, 3, 1}, 4);
    ordered_array_set set2 =
            ordered_array_set_create_from_array(
                    (int[]) {3, 1, 0}, 3);

    assert(!ordered_array_set_isSubset(set2, set1));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
}

void test_ordered_array_set_isSubset() {
    test_ordered_array_set_isSubset1();
    test_ordered_array_set_isSubset2();
}

void test_ordered_array_set_insert1() {
    for (int i = 0; i < 100000; ++i) {
        ordered_array_set set = ordered_array_set_create(3);
        ordered_array_set_insert(&set, 2);
        ordered_array_set_insert(&set, 1);
        ordered_array_set_insert(&set, 3);
        ordered_array_set result =
                ordered_array_set_create_from_array(
                        (int[]) {1, 2, 3}, 3);
        bool res = ordered_array_set_isEqual(set, result);
        if (!res) {
            printf("%d %d\n", i, set.size);
            printArray(set.data, 3);
            ordered_array_set_print(set);
            ordered_array_set_print(result);
        }
        assert(res);

        ordered_array_set_delete(set);
        ordered_array_set_delete(result);
    }
}

void test_ordered_array_set_insert2() {
    ordered_array_set set = ordered_array_set_create(3);
    ordered_array_set_insert(&set, 3);
    ordered_array_set_insert(&set, 1);
    ordered_array_set_insert(&set, 3);
    ordered_array_set result =
            ordered_array_set_create_from_array(
                    (int[]) {1, 3}, 2);
    assert(ordered_array_set_isEqual(set, result));

    ordered_array_set_delete(set);
    ordered_array_set_delete(result);
}

void test_ordered_array_set_insert() {
    test_ordered_array_set_insert1();
    test_ordered_array_set_insert2();
}

void test_ordered_array_set_union1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array(
                    (int[]) {1, 3, 4, 6}, 4);
    ordered_array_set set2 =
            ordered_array_set_create_from_array(
                    (int[]) {0, 5}, 2);
    ordered_array_set result =
            ordered_array_set_create_from_array(
                    (int[]) {0, 1, 3, 4, 5, 6}, 6);
    ordered_array_set expectedSet =
            ordered_array_set_union(set1, set2);
    assert(ordered_array_set_isEqual(expectedSet, result));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(result);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array(
                    (int[]) {1, 3, 4, 6}, 4);
    ordered_array_set set2 =
            ordered_array_set_create_from_array(
                    (int[]) {0, 4, 5}, 3);
    ordered_array_set result =
            ordered_array_set_create_from_array(
                    (int[]) {0, 1, 3, 4, 5, 6}, 6);
    ordered_array_set expectedSet =
            ordered_array_set_union(set1, set2);
    assert(ordered_array_set_isEqual(expectedSet, result));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(result);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union() {
    test_ordered_array_set_union1();
    test_ordered_array_set_union2();
}

void test_ordered_array_set_intersection1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array(
                    (int[]) {1, 3, 4, 6}, 4);
    ordered_array_set set2 =
            ordered_array_set_create_from_array(
                    (int[]) {0, 5}, 2);
    ordered_array_set result =
            ordered_array_set_create(0);
    ordered_array_set expectedSet =
            ordered_array_set_intersection(set1, set2);
    assert(ordered_array_set_isEqual(expectedSet, result));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(result);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array(
                    (int[]) {1, 3, 4, 6}, 4);
    ordered_array_set set2 =
            ordered_array_set_create_from_array(
                    (int[]) {0, 4, 5}, 3);
    ordered_array_set result =
            ordered_array_set_create_from_array(
                    (int[]) {4}, 1);
    ordered_array_set expectedSet =
            ordered_array_set_intersection(set1, set2);
    assert(ordered_array_set_isEqual(expectedSet, result));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(result);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection() {
    test_ordered_array_set_intersection1();
    test_ordered_array_set_intersection2();
}

void test_ordered_array_set_difference1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array(
                    (int[]) {1, 3, 4, 6}, 4);
    ordered_array_set set2 =
            ordered_array_set_create_from_array(
                    (int[]) {0, 5}, 2);
    ordered_array_set result =
            ordered_array_set_create_from_array(
                    (int[]) {1, 3, 4, 6}, 4);
    ordered_array_set expectedSet =
            ordered_array_set_difference(set1, set2);
    assert(ordered_array_set_isEqual(expectedSet, result));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(result);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array(
                    (int[]) {1, 3, 4, 6}, 4);
    ordered_array_set set2 =
            ordered_array_set_create_from_array(
                    (int[]) {0, 4, 5}, 3);
    ordered_array_set result =
            ordered_array_set_create_from_array(
                    (int[]) {1, 3, 6}, 3);
    ordered_array_set expectedSet =
            ordered_array_set_difference(set1, set2);
    assert(ordered_array_set_isEqual(expectedSet, result));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(result);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference() {
    test_ordered_array_set_difference1();
    test_ordered_array_set_difference2();
}

void test_ordered_array_set_symmetricDifference1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1}, 4);
    ordered_array_set set2 =
            ordered_array_set_create_from_array(
                    (int[]) {0, 5}, 2);
    ordered_array_set result =
            ordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1, 0, 5}, 6);
    ordered_array_set expectedSet =
            ordered_array_set_symmetricDifference(set1, set2);
    assert(ordered_array_set_isEqual(expectedSet, result));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(result);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array(
                    (int[]) {3, 6, 4, 1}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array(
                    (int[]) {0, 5, 4, 6}, 4);
    unordered_array_set result =
            unordered_array_set_create_from_array(
                    (int[]) {3, 1, 0, 5}, 4);
    unordered_array_set expectedSet =
            unordered_array_set_symmetricDifference(set1, set2);
    assert(unordered_array_set_isEqual(expectedSet, result));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(result);
    unordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference() {
    test_ordered_array_set_symmetricDifference1();
    test_ordered_array_set_symmetricDifference2();
}

void test_ordered_array_set() {
    test_ordered_array_set_in();
    test_ordered_array_set_isSubset();
    test_ordered_array_set_insert();
    test_ordered_array_set_union();
    test_ordered_array_set_intersection();
    test_ordered_array_set_difference();
    test_ordered_array_set_symmetricDifference();
}

void test_bool_array_set_create() {
    bool_array_set set = bool_array_set_create(5);
    bool result[6] = {};

    ASSERT_BOOL_SET(result, set);

    bool_array_set_delete(set);
}

void test_bool_array_set_create_from_array_null() {
    bool_array_set set = bool_array_set_create_from_array(
            (int[]) {}, 0);

    ASSERT_BOOL_SET((bool[]) {false}, set);
    bool_array_set_delete(set);
}

void test_bool_array_set_create_from_array_oneElem() {
    bool_array_set set;

    set = bool_array_set_create_from_array((int[]) {0}, 1);
    bool result0[] = {true};
    ASSERT_BOOL_SET(result0, set);
    bool_array_set_delete(set);

    set = bool_array_set_create_from_array((int[]) {2}, 1);
    bool result2[] = {false, false, true};
    ASSERT_BOOL_SET(result2, set);
    bool_array_set_delete(set);
}

void test_bool_array_set_create_from_array_twoElem() {
    bool_array_set set;

    set = bool_array_set_create_from_array((int[]) {0, 1}, 2);
    bool result1[] = {true, true};
    ASSERT_BOOL_SET(result1, set);
    bool_array_set_delete(set);

    set = bool_array_set_create_from_array((int[]) {5, 2}, 2);
    bool result2[] = {false, false, true, false, false, true};
    ASSERT_BOOL_SET(result2, set);
    bool_array_set_delete(set);

    set = bool_array_set_create_from_array((int[]) {1, 1}, 2);
    bool result3[] = {false, true};
    ASSERT_BOOL_SET(result3, set);
    bool_array_set_delete(set);
}

void test_bool_array_set_create_from_array() {
    test_bool_array_set_create_from_array_null();
    test_bool_array_set_create_from_array_oneElem();
    test_bool_array_set_create_from_array_twoElem();
}

void test_bool_array_set_in() {
    bool_array_set set = bool_array_set_create_from_array(
            (int[]) {5, 4, 7}, 3);

    int value = 0;
    ASSERT_BOOL(!bool_array_set_in(set, value++))
    ASSERT_BOOL(!bool_array_set_in(set, value++))
    ASSERT_BOOL(!bool_array_set_in(set, value++))
    ASSERT_BOOL(!bool_array_set_in(set, value++))
    ASSERT_BOOL(bool_array_set_in(set, value++))
    ASSERT_BOOL(bool_array_set_in(set, value++))
    ASSERT_BOOL(!bool_array_set_in(set, value++))
    ASSERT_BOOL(bool_array_set_in(set, value++))
    ASSERT_BOOL(!bool_array_set_in(set, value++))
    ASSERT_BOOL(!bool_array_set_in(set, value++))

    bool_array_set_delete(set);
}

void test_bool_array_set_isEqual() {
    bool_array_set set1 = bool_array_set_create(5);
    bool_array_set set2 = bool_array_set_create(3);

    ASSERT_BOOL(bool_array_set_isEqual(set1, set2))

    bool_array_set_insert(set1, 2);
    ASSERT_BOOL(!bool_array_set_isEqual(set1, set2))

    bool_array_set_insert(set2, 2);
    ASSERT_BOOL(bool_array_set_isEqual(set1, set2))

    bool_array_set_insert(set1, 5);
    ASSERT_BOOL(!bool_array_set_isEqual(set1, set2))

    bool_array_set_delete(set1);
    bool_array_set_delete(set2);
}

void test_bool_array_set_isSubset() {
    bool_array_set set1 = bool_array_set_create(3);
    bool_array_set set2 = bool_array_set_create(5);

    ASSERT_BOOL(bool_array_set_isSubset(set1, set2))

    bool_array_set_insert(set1, 2);
    ASSERT_BOOL(!bool_array_set_isSubset(set1, set2))

    bool_array_set_insert(set2, 2);
    ASSERT_BOOL(bool_array_set_isSubset(set1, set2))

    bool_array_set_insert(set2, 5);
    ASSERT_BOOL(bool_array_set_isSubset(set1, set2))

    bool_array_set_delete(set1);
    bool_array_set_delete(set2);
}

void test_bool_array_set_insert() {
    bool_array_set set = bool_array_set_create(5);
    bool result[6] = {};

    for (int value = 0; value < 6; ++value) {
        bool_array_set_insert(set, value);
        result[value] = true;
        ASSERT_BOOL_SET(result, set);
    }
}

void test_bool_array_set_deleteElement() {
    bool_array_set set =
            bool_array_set_create_from_array(
                    (int[]) {0, 1, 2, 3, 4, 5},
                    6);
    bool result[6] = {true, true, true, true, true, true};

    for (int value = 0; value < 6; ++value) {
        bool_array_set_deleteElement(set, value);
        result[value] = false;
        ASSERT_BOOL_SET(result, set);
    }
}

void test_bool_array_set_union() {
    bool_array_set set1 =
            bool_array_set_create_from_array(
                    (int[]) {0, 1, 5},
                    3);
    bool_array_set set2 =
            bool_array_set_create_from_array(
                    (int[]) {1, 2, 3, 4},
                    4);
    bool result[6] = {true, true, true, true, true, true};

    bool_array_set set3 = bool_array_set_union(set1, set2);

    ASSERT_BOOL_SET(result, set3);

    bool_array_set_delete(set1);
    bool_array_set_delete(set2);
    bool_array_set_delete(set3);
}

void test_bool_array_set_intersection() {
    bool_array_set set1 =
            bool_array_set_create_from_array(
                    (int[]) {0, 1, 5},
                    3);
    bool_array_set set2 =
            bool_array_set_create_from_array(
                    (int[]) {1, 2, 3, 4, 6},
                    5);
    bool result[6] = {false, true, false, false, false, false};

    bool_array_set set3 = bool_array_set_intersection(set1, set2);

    ASSERT_BOOL_SET(result, set3);

    bool_array_set_delete(set1);
    bool_array_set_delete(set2);
    bool_array_set_delete(set3);
}

void test_bool_array_set_difference() {
    bool_array_set set1 =
            bool_array_set_create_from_array(
                    (int[]) {0, 1, 5, 4},
                    4);
    bool_array_set set2 =
            bool_array_set_create_from_array(
                    (int[]) {1, 2, 3, 4, 6},
                    5);
    bool result[6] = {true, false, false, false, false, true};

    bool_array_set set3 = bool_array_set_difference(set1, set2);

    ASSERT_BOOL_SET(result, set3);

    bool_array_set_delete(set1);
    bool_array_set_delete(set2);
    bool_array_set_delete(set3);
}

void test_bool_array_set_symmetricDifference() {
    bool_array_set set1 =
            bool_array_set_create_from_array(
                    (int[]) {0, 1, 5, 4},
                    4);
    bool_array_set set2 =
            bool_array_set_create_from_array(
                    (int[]) {1, 2, 3, 4, 6},
                    5);
    bool result[7] = {true, false, true, true, false, true, true};

    bool_array_set set3 = bool_array_set_symmetricDifference(set1, set2);

    ASSERT_BOOL_SET(result, set3);

    bool_array_set_delete(set1);
    bool_array_set_delete(set2);
    bool_array_set_delete(set3);
}

void test_bool_array_set_complement() {
    bool_array_set universe =
            bool_array_set_create_from_array(
                    (int[]) {0, 1, 2, 3, 4, 5},
                    6);
    bool_array_set set1 =
            bool_array_set_create_from_array(
                    (int[]) {0, 1, 5, 4},
                    4);
    bool result[6] = {false, false, true, true, false, false};

    bool_array_set set2 = bool_array_set_complement(set1, universe);

    ASSERT_BOOL_SET(result, set2);

    bool_array_set_delete(universe);
    bool_array_set_delete(set1);
    bool_array_set_delete(set2);
}

void test_bool_array_set() {
    test_bool_array_set_create();
    test_bool_array_set_create_from_array();
    test_bool_array_set_in();
    test_bool_array_set_isEqual();
    test_bool_array_set_isSubset();
    test_bool_array_set_insert();
    test_bool_array_set_deleteElement();
    test_bool_array_set_union();
    test_bool_array_set_intersection();
    test_bool_array_set_difference();
    test_bool_array_set_symmetricDifference();
    test_bool_array_set_complement();
}

void test() {
    test_bitset();
    test_unordered_array_set();
    test_ordered_array_set();
    test_bool_array_set();
}
