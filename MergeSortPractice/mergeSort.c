#include <stdio.h>
#include "mergeSort.h"

void merge(int arr[], int left, int middle, int right) {
	int i, j, k;
	int sorted_arr[MAX];//�ӽù迭
	i = left;//ù��° �κ� �迭�� ���� �ε���
	j = middle + 1;//�ι�° �κ� �迭�� ���� �ε���
	k = left;//sorted_arr�� ���� ������ �ε���

	//�� �κ� �迭�� ��Ҹ� ���ϸ� sorted_arr�� ����
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