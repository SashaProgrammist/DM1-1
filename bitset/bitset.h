# ifndef INC_BITSET_H
# define INC_BITSET_H

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

#define MAX_MAX_VALUE 31

typedef struct bitset {
    uint32_t values;   // ���������
    uint32_t maxValue; // ������������ ������� ����������
} bitset;

// ���������� ���������  0, 1,..., maxValue
unsigned getUniverse(unsigned maxValue);

// ���������� ������ ��������� c ����������� 0, 1,..., maxValue
bitset bitset_create(unsigned maxValue);

// ���������� �������� ��������, 
// ���� �������� value ������� � ��������� set
// ����� - ������
bool bitset_in(bitset set, unsigned value);

// ���������� �������� ��������, ���� ��������� set1 � set2 �����
// ����� - ������
bool bitset_isEqual(bitset set1, bitset set2);

// ���������� �������� �������� ���� ��������� subset
// �������� ������������� ��������� set, ����� - ������.
bool bitset_isSubset(bitset subset, bitset set);

// ��������� ������� value � ��������� set
void bitset_insert(bitset *set, unsigned value);

// ������� ������� value �� ��������� set
void bitset_deleteElement(bitset * set, unsigned value);

// ���������� ����������� �������� set1 � set2
bitset bitset_union(bitset set1, bitset set2);

// ���������� ����������� �������� set1 � set2
bitset bitset_intersection(bitset set1, bitset set2);

// ���������� �������� �������� set1 � set2
bitset bitset_difference(bitset set1, bitset set2);

// ���������� �������������� �������� �������� set1 � set2
bitset bitset_symmetricDifference(bitset set1, bitset set2);

// ���������� ���������� �� ���������� ��������� set
bitset bitset_complement(bitset set);

// ����� ��������� set
void bitset_print(bitset set);

# endif