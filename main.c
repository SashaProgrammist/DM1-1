#include "bool_array_set/bool_array_set.h"

void test();

void paragraph_a() {
    bool_array_set universe =
            bool_array_set_create_from_array(
                    (int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                    10);

    bool_array_set A = bool_array_set_create_from_array(
            (int[]) {1, 2, 3, 4, 8}, 5);
    bool_array_set B = bool_array_set_create_from_array(
            (int[]) {2, 3, 8}, 3);
    bool_array_set C = bool_array_set_create_from_array(
            (int[]) {3, 4, 5, 6, 7}, 5);

    bool_array_set temp1 = bool_array_set_union(C, B);
    bool_array_set temp2 = bool_array_set_intersection(A, B);
    bool_array_set temp3 = bool_array_set_difference(temp2, A);
    bool_array_set temp4 = bool_array_set_symmetricDifference(temp3, temp1);
    bool_array_set temp5 = bool_array_set_difference(temp4, B);
    bool_array_set temp6 = bool_array_set_symmetricDifference(temp5, A);
    bool_array_set temp7 = bool_array_set_complement(temp6, universe);

    printf("D = ");
    bool_array_set_print(temp7);
    printf("\n");

    bool_array_set_delete(universe);
    bool_array_set_delete(A);
    bool_array_set_delete(B);
    bool_array_set_delete(C);
    bool_array_set_delete(temp1);
    bool_array_set_delete(temp2);
    bool_array_set_delete(temp3);
    bool_array_set_delete(temp4);
    bool_array_set_delete(temp5);
    bool_array_set_delete(temp6);
    bool_array_set_delete(temp7);
}

void paragraph_b() {
    bool_array_set universe =
            bool_array_set_create_from_array(
                    (int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                    10);

    bool_array_set A = bool_array_set_create_from_array(
            (int[]) {1, 2, 3, 4, 6, 7}, 6);
    bool_array_set notA = bool_array_set_complement(A, universe);
    bool_array_set B = bool_array_set_create_from_array(
            (int[]) {1, 3, 6, 7}, 4);
    bool_array_set notB = bool_array_set_complement(B, universe);
    bool_array_set C = bool_array_set_create_from_array(
            (int[]) {3, 4, 5, 6, 8}, 5);
    bool_array_set notC = bool_array_set_complement(C, universe);
    bool_array_set D = bool_array_set_create_from_array(
            (int[]) {1, 5, 7, 8}, 5);

    bool_array_set result = bool_array_set_create(7);

    for (int i = 0; i < 8; ++i) {
        bool_array_set curA = (i & 1) ? A : notA;
        bool_array_set curB = (i & 2) ? B : notB;
        bool_array_set curC = (i & 4) ? C : notC;

        bool_array_set curAB = bool_array_set_intersection(curA, curB);
        bool_array_set curABC = bool_array_set_intersection(curAB, curC);

        if (!bool_array_set_isNull(curABC) &&
            bool_array_set_isSubset(curABC, D))
            bool_array_set_insert(result, i);

        bool_array_set_delete(curAB);
        bool_array_set_delete(curABC);
    }

    printf("D = ");
    for (int i = 0; i < 8; ++i)
        if (result.data[i]) {
            if (!(i & 1))
                printf("~");
            printf("A & ");

            if (!(i & 2))
                printf("~");
            printf("B & ");

            if (!(i & 4))
                printf("~");
            printf("C | ");
        }

    printf("\b\b  \n");

    bool_array_set_delete(universe);
    bool_array_set_delete(A);
    bool_array_set_delete(B);
    bool_array_set_delete(C);
}

int main() {
    test();

    paragraph_a();
    paragraph_b();

    return 0;
}
