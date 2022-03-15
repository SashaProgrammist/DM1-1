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

int main() {
    test();

    paragraph_a();

    return 0;
}
