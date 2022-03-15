# ifndef INC_UNORDERED_ARRAY_SET_H
# define INC_UNORDERED_ARRAY_SET_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define min(a, b) (a < b ? a : b)

typedef struct unordered_array_set {
    int *data;       // �������� ���������
    size_t size;     // ���������� ��������� � ���������
    size_t capacity; // ������������ ���������� ��������� � ���������
} unordered_array_set;

// ���������� ������ ��������� ��� capacity ���������
unordered_array_set unordered_array_set_create(size_t capacity);

// ���������� ���������, ��������� �� ��������� ������� a ������� size
unordered_array_set unordered_array_set_create_from_array(
    const int *a, size_t size
);

// ���������� ������ �������� � ���������,
// ���� �������� value ������� � ��������� set,
// ����� - set.capacity
size_t unordered_array_set_in(unordered_array_set set, int value);

// ���������� �������� ��������, ���� �������� �������� set1 � set2 �����
// ����� - ������
bool unordered_array_set_isEqual(
    unordered_array_set set1, unordered_array_set set2
);

// ���������� �������� ��������, 
// ���� subset �������� ������������� set
// ����� - ������
bool unordered_array_set_isSubset(unordered_array_set subset,
                                  unordered_array_set set);

// ���������� ����������, ���� � ��������� �� ������ set
// ������ �������� �������
void unordered_array_set_isAbleAppend(unordered_array_set *set);

// ��������� ������� value � ��������� set
void unordered_array_set_insert(
    unordered_array_set *set, int value
);

// ������� ������� value �� ��������� set
void unordered_array_set_deleteElement(
    unordered_array_set *set, int value
);

// ���������� ����������� �������� set1 � set2
unordered_array_set unordered_array_set_union(
    unordered_array_set set1, unordered_array_set set2
);

// ���������� ����������� �������� set1 � set2
unordered_array_set unordered_array_set_intersection(
    unordered_array_set set1, unordered_array_set set2
);

// ���������� �������� �������� set1 � set2
unordered_array_set unordered_array_set_difference(
    unordered_array_set set1, unordered_array_set set2
);

// ���������� �������������� �������� �������� set1 � set2
unordered_array_set unordered_array_set_symmetricDifference(
    unordered_array_set set1, unordered_array_set set2
);

// ���������� ���������� �� ���������� ��������� set
unordered_array_set unordered_array_set_complement(
    unordered_array_set set, unordered_array_set universumSet
);

// ����� ��������� set
void unordered_array_set_print(unordered_array_set set);

// ����������� ������, ���������� ���������� set
void unordered_array_set_delete(unordered_array_set set);

// ���������� ����� set
unordered_array_set unordered_array_set_cpy(
    unordered_array_set set
);

// ��������� set.data �� ������� set.size + add
void unordered_array_set_expand(
    unordered_array_set *set, size_t add
);

# endif