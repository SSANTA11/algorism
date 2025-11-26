//#include <stdio.h>
//void selectionSort(int a[], int size) {
//	int i, j, t, min, temp;
//
//	for (i = 0; i < size - 1; i++) {
//		min = i;
//		for (j = i + 1; j < size; j++) {
//			if (a[j] < a[min]) min = j;
//		}
//		temp = a[i];
//		a[i] = a[min];
//		a[min] = temp;
//		printf("\n%d단계 : ", i + 1);
//		for (t = 0; t < size; t++)  printf("%3d ", a[t]);
//	}
//}
//int main() {
//	int arr[4] = { 50,40,90,10 };
//
//	selectionSort(arr, 4);
//}

#include <stdio.h>

void selectionSort(int a[], int size) {
	int min, tmp;
	for (int i = 0; i < size-1; i++) {
		min = 1 + i;
		for (int j = i + 2; j < size; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		if (a[i] > a[min]) {
			tmp = a[i];
			a[i] = a[min];
			a[min] = tmp;
		}
		printf("\n%d 단계: \n", i + 1);
		for (int i = 0; i < size; i++) {
			printf("%4d", a[i]);
		}
	}
}
int main() {
	int arr[] = { 3,4,5,1,6,2 };
	selectionSort(arr, 6);
}
