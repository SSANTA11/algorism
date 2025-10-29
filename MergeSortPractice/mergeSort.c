#include "mergeSort.h"
void merge(int arr[], int left, int middle, int right) {
	int i, j, k;
	i = left; // 첫번째 부분 배열의 시작 인덱스
	j = middle + 1; // 두번째 부분 배열의 시작 인덱스
	k = left; // sorted_arr에 값을 저장할 인덱스

	// 두 부분 배열의 요소를 비교하며 sorted_arr에 복사
	while (i <= middle && j <= right) {
		if (arr[i] <= arr[j]) {
			sorted_arr[k++] = arr[i++];
		} else {
			sorted_arr[k++] = arr[j++];
		}
	}
	while (i <= middle)
		sorted_arr[k++] = arr[i++];
	while (j <= right)
		sorted_arr[k++] = arr[j++];

	// 정렬된 배열을 원본 배열에 복사
	for (int i = left; i <= right; i++) {
		arr[i] = sorted_arr[i];
	}
	for (int i = 0; i < MAX; i++)
		printf("%4d ",sorted_arr[i]);
	printf("\n");
}

void mergeSort(int a[], int left, int right) {
	int m;
	if (left < right) {
		m = (right + left) / 2;
		mergeSort(a, left, m);
		mergeSort(a, m + 1, right);
		merge(a, left, m, right);
	}
}