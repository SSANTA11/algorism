#pragma once
#include <stdio.h>

#define MAX 30

extern int size; // 다른 파일에 정의된 size 변수 사용을 알림
extern int sorted[MAX]; // 다른 파일에 정의된 sorted 배열 사용을 알림

void merge(int a[], int m, int middle, int n); // 함수 선언
void mergeSort(int a[], int m, int n); // 함수 선언