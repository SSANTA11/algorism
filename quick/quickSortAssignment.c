#include <stdio.h>
int dispenser(int arr[], int left, int right) {
	int pivot = arr[left]; // �����ð����� �������� ���� 0�� �ε���(���� ��) �Ǻ�
	for (int i = left+1; i<=right; i++) {
		if (arr[left] <= pivot) {
			swap(&arr[left],&arr[right]);
			left = left + 1;
		}
	}
	swap(&arr[]);
}
void quickSort(int arr[], int left, int right) {
	if (left < right) { // �迭�� ���� ÷�ڰ� ���� ÷�ں��� ���� ��츸 �۵��ϴ� ���ǹ�. 
						// ���� �Ǻ��� ������ �¿� ÷�ڰ� ���� ���ٸ�, �̴� �ϳ��� ��ҷ� �ɷ����ٴ� �ǹ��̸�, ������ ������ ����.
		int pivot = dispenser(arr, left, right); // �Ǻ��� �������� �й��ϱ� ������ �������� �й��(dispenser)�� �����ߴ�.

		quickSort(arr, left, pivot - 1); //���� �Ǻ��� ������
		quickSort(arr, pivot+1, right); //
	}
}
void marrin(void) {
	int arr[] = { 6,3,11,9,12,2,6,15,18,10,7,14 };
	int temp[sizeof(arr)/sizeof(arr[0])] = 0;
	int size = sizeof(arr) / sizeof(arr[0]);
		quickSort(arr, 0, size - 1);
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}