#include <stdio.h>
int dispenser(int arr[], int left, int right) {
	int pivot = arr[left]; // 수업시간에서 기준으로 잡은 0번 인덱스(좌측 끝) 피봇
	for (int i = left+1; i<=right; i++) {
		if (arr[left] <= pivot) {
			swap(&arr[left],&arr[right]);
			left = left + 1;
		}
	}
	swap(&arr[]);
}
void quickSort(int arr[], int left, int right) {
	if (left < right) { // 배열의 좌측 첨자가 우측 첨자보다 작을 경우만 작동하는 조건문. 
						// 만약 피봇을 제외한 좌우 첨자가 서로 같다면, 이는 하나의 요소로 걸러졌다는 의미이며, 루프에 들어오지 않음.
		int pivot = dispenser(arr, left, right); // 피봇을 기준으로 분배하기 때문에 변수명을 분배기(dispenser)로 지정했다.

		quickSort(arr, left, pivot - 1); //좌측 피봇을 제외한
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