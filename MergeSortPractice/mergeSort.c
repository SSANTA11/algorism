#include <stdio.h>
#include "mergeSort.h"

void merge(int arr[], int left, int middle, int right) {
	int i, j, k;
	int sorted_arr[MAX];//임시배열
	i = left;//첫번째 부분 배열의 시작 인덱스
	j = middle + 1;//두번째 부분 배열의 시작 인덱스
	k = left;//sorted_arr에 값을 저장할 인덱스

	//두 부분 배열의 요소를 비교하며 sorted_arr에 복사
	while (i <= middle && j <= right) {
		if (arr[i] <= arr[j]) {
			sorted_arr[k++] = arr[i++];
		}
		else {
			sorted_arr[k++] = arr[j++];
		}
	}
	while (i <= middle) {

	}
}