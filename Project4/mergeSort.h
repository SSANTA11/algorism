#pragma once
#include <stdio.h>

#define MAX 30

extern int size; // �ٸ� ���Ͽ� ���ǵ� size ���� ����� �˸�
extern int sorted[MAX]; // �ٸ� ���Ͽ� ���ǵ� sorted �迭 ����� �˸�

void merge(int a[], int m, int middle, int n); // �Լ� ����
void mergeSort(int a[], int m, int n); // �Լ� ����