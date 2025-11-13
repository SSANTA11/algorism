#include <stdio.h>
//연속 행렬 곱셈 (Chained Matrix Multiplications)
	// 연속된 행렬들의 곱셈에 필요한 원소 간의 최소 곱셈 횟수를 찾는 문제
int main() {
	int a[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	int b[3][4] = {
		{1,2,3,5},
		{0,1,1,2},
		{4,3,2,3}
	};

	int c[5][5] = { 0 };

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 3; k++)
				c[i][j] += a[i][k] * b[k][j];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			printf("%4d", c[i][j]);
		printf("\n");
	}
}


//행렬 직접 구현해보기!
