#include <stdio.h>
//void bubbleSort(int a[], int size) {
//	int i, j, t, temp;
//
//	for (i = size - 1; i > 0; i--) {
//		printf("\n %d단계>>", size - i);
//		for (j = 0; j < i; j++) {
//			if (a[j] > a[j + 1]) {
//				temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//			printf("\n\t");
//			for (t = 0; t < size; t++) printf("%3d ", a[t]);
//		}
//	}
//}
//int main() {
//	int arr[4] = { 50,40,90,10 };
//
//	bubbleSort(arr,4);
//}

void bubbleSort(int a[], int size) {
	int tmp;
	for (int j = size - 1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (a[i] > a[i + 1]) {
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		}
		printf("\n%d 단계\n", size - j);
		for (int i = 0; i < size; i++) {
			printf("%4d", a[i]);
		}
	}
}
int main() {
	int arr[4] = { 50,40,90,10 };

	bubbleSort(arr, 4);
}