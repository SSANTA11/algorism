#include <stdio.h>

    // ������ �������� �ڵ� �ϼ� ����, partition �Լ� �ڵ尡 �������غ��� �߰��� 3�� ��ȯ �Լ� swap...!
void swap(int* a, int* b) {//swap�Լ��� �Ű������� *a�� *b�� �޴µ� �̴� �� ������ �ּҰ��� �޾� temp�� �ӽ� ������ �� 
    // a�� b�� �ּҰ��� ���� �ٲ��ش�.
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ���� �� ��Ҹ� �ǹ����� ����ϴ� partition �Լ�
int partition(int a[], int begin, int end) {
    int pivot_value = a[begin]; // �Ǻ��� ���� �ð����� ���õ� ������ ���� �Ǻ����� �����Ѵ�.
    int L = begin + 1; // ���� �ε��� ������ L (�ε����� ����Ų�ٴ� �ǹ��� ������ L, R), +1 �� ���� �Ǻ��� �����ϱ� ����.
    int R = end; // ���� �ε��� ������ R

    while (L <= R) { // ���� L �����Ͱ� R ������ ���� �۰ų� ���ٸ�...!
        while (L <= end && a[L] <= pivot_value) // ���� ������ �̵��� �ǹ����� ũ�ų� ���� ���� ���� �����ϴ�. 
            // ���⼭ L <= end�� �������� ���� ������ ��Ͱ� �ݺ��� ��, �Ǻ��� �迭 ������ Ŭ �� ������ �ε����� end�� �ʰ��� �� �ֱ� �����̴�.
            L++;
        while (R >= begin && a[R] > pivot_value) // ������ ������ �̵� (�ǹ����� ���� �� ã��)
            R--;

        if (L < R) { // ���� �� ���ǿ��� ��� Ż���� ������, �¿� �����Ͱ� �������� �ʾҴٸ� �ݺ��Ǵ� �ǹ� ���� �¿� ��ȯ��ġ
            swap(&a[L], &a[R]);
        }
    }
    swap(&a[begin], &a[R]); // �����ͷ� �ּҰ��� ��ȯ
    // �¿� �����Ͱ� ������ �� ������ ��ġ�� �ǹ��� ���� ������ �ڸ��� ��ü�Ͽ� 
    // �ǹ��� ������ ��ġ�� ��ġ�Ѵ�(��ġ �� �� ��ġ�� �ǹ��� ���� �����ϴ�.)
    return R; // �ǹ��� ���� ��ġ�� ��ȯ�Ѵ�.
}

void quickSort(int a[], int begin, int end) {
    if (begin < end) {
        int pivot_index = partition(a, begin, end);
        quickSort(a, begin, pivot_index - 1);// �Ǻ��� ������ �յ� �ε��� ���� �̻��� �ٷ絵�� �Ͽ�, �Ǻ� ���� ���� �׷�� ū �׷����� ������.
        quickSort(a, pivot_index + 1, end);
    }
}

int main() {
    int arr[] = { 6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14 };
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    printf("���ĵ� �迭: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); //call by reference�� ���� ������ ������ ���õȴ�!
    }
    printf("\n");

    return 0;
}