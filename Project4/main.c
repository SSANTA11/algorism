#include "mergeSort.h"

// main 함수가 있는 파일에서만 전역 변수 size 정의
int size;

void main(void) {
    int i, list[8] = { 2, 7, 3, 1, 8, 6, 4, 5 };
    size = sizeof(list) / sizeof(list[0]);

    printf("\n 정렬할 원소 >> ");
    for (i = 0; i < size; i++) 
        printf("%4d ", list[i]);
    printf("\n\n<<<<<<<<< 병합 정렬 수행 >>>>>>>>>>\n");

    mergeSort(list, 0, size - 1);

}