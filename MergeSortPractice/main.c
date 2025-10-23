#include "mergeSort.h"
int main(void) {
	int arr[MAX] = { 8,6,2,3,4,5,1,7 };
	printf("정렬된 배열");
	printf("\n");

	mergeSort(arr, 0, MAX-1);
}