#include "mergeSort.h"
void merge(int arr[], int left, int middle, int right) {
	int i, j, k;
	i = left; // ù��° �κ� �迭�� ���� �ε���
	j = middle + 1; // �ι�° �κ� �迭�� ���� �ε���
	k = left; // sorted_arr�� ���� ������ �ε���

	// �� �κ� �迭�� ��Ҹ� ���ϸ� sorted_arr�� ����
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

	// ���ĵ� �迭�� ���� �迭�� ����
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