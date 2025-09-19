#include "mergeSort.h"
#include <stdio.h>

int main(void) {
	int arr[MAX] = { 8,6,9,10,2,3,4,5,1,7 };
	mergeSort(arr, 0, MAX-1);
}