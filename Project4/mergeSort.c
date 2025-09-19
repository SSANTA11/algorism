#include "mergeSort.h"

// 전역 변수 정의는 한 곳에서만!
int sorted[MAX];

void merge(int a[], int m, int middle, int n) {
    // ... merge 함수 구현 내용 ...
    int i, j, k, t;
    i = m;
    j = middle + 1;
    k = m;

    while (i <= middle && j <= n) {
        if (a[i] <= a[j])
            sorted[k++] = a[i++];
        else
            sorted[k++] = a[j++];
    }

    if (i > middle)
        for (t = j; t <= n; t++, k++) 
            sorted[k] = a[t];
    else
        for (t = i; t <= middle; t++, k++) 
            sorted[k] = a[t];

    for (t = m; t <= n; t++) 
        a[t] = sorted[t];

    printf("\n 병합 정렬 >> ");
    for (t = 0; t < size; t++) 
        printf("%4d ", sorted[t]);
}

void mergeSort(int a[], int m, int n) {
    int middle;
    if (m < n) {
        middle = (m + n) / 2;
        mergeSort(a, m, middle);
        mergeSort(a, middle + 1, n);
        merge(a, m, middle, n);
    }
}