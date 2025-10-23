#pragma once
#include <stdio.h>
#define MAX 8
int sorted_arr[MAX];
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int left, int middle, int right);