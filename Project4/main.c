#include "mergeSort.h"

// main �Լ��� �ִ� ���Ͽ����� ���� ���� size ����
int size;

void main(void) {
    int i, list[8] = { 2, 7, 3, 1, 8, 6, 4, 5 };
    size = sizeof(list) / sizeof(list[0]);

    printf("\n ������ ���� >> ");
    for (i = 0; i < size; i++) 
        printf("%4d ", list[i]);
    printf("\n\n<<<<<<<<< ���� ���� ���� >>>>>>>>>>\n");

    mergeSort(list, 0, size - 1);

}