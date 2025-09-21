#include <stdio.h>

    // 기존엔 없었으나 코드 완성 이후, partition 함수 코드가 지저분해보여 추가한 3자 변환 함수 swap...!
void swap(int* a, int* b) {//swap함수는 매개변수로 *a와 *b를 받는데 이는 각 변수의 주소값을 받아 temp에 임시 저장한 후 
    // a와 b의 주소값을 서로 바꿔준다.
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 좌측 끝 요소를 피벗으로 사용하는 partition 함수
int partition(int a[], int begin, int end) {
    int pivot_value = a[begin]; // 피봇은 수업 시간에서 제시된 기준인 좌측 피봇으로 시작한다.
    int L = begin + 1; // 좌측 인덱스 포인터 L (인덱스를 가르킨다는 의미의 포인터 L, R), +1 된 것은 피봇을 제외하기 위함.
    int R = end; // 우측 인덱스 포인터 R

    while (L <= R) { // 만약 L 포인터가 R 포인터 보다 작거나 같다면...!
        while (L <= end && a[L] <= pivot_value) // 왼쪽 포인터 이동은 피벗보다 크거나 같은 값일 때만 가능하다. 
            // 여기서 L <= end가 조건으로 들어가는 이유는 재귀가 반복될 때, 피봇이 배열 끝보다 클 때 마지막 인덱스인 end를 초과할 수 있기 때문이다.
            L++;
        while (R >= begin && a[R] > pivot_value) // 오른쪽 포인터 이동 (피벗보다 작은 값 찾기)
            R--;

        if (L < R) { // 위에 두 조건에서 모두 탈출할 때마다, 좌우 포인터가 교차하지 않았다면 반복되는 피벗 기준 좌우 교환배치
            swap(&a[L], &a[R]);
        }
    }
    swap(&a[begin], &a[R]); // 포인터로 주소값을 교환
    // 좌우 포인터가 엇갈린 뒤 좌측에 위치한 피벗을 우측 포인터 자리와 교체하여 
    // 피벗을 적절한 위치에 배치한다(배치 될 시 위치는 피벗에 따라 상이하다.)
    return R; // 피벗의 최종 위치를 반환한다.
}

void quickSort(int a[], int begin, int end) {
    if (begin < end) {
        int pivot_index = partition(a, begin, end);
        quickSort(a, begin, pivot_index - 1);// 피봇을 제외한 앞뒤 인덱스 이하 이상을 다루도록 하여, 피봇 기준 작은 그룹과 큰 그룹으로 나눈다.
        quickSort(a, pivot_index + 1, end);
    }
}

int main() {
    int arr[] = { 6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14 };
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    printf("정렬된 배열: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); //call by reference로 인해 수정된 원본이 제시된다!
    }
    printf("\n");

    return 0;
}