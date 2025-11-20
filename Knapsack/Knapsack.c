#include <stdio.h>

int max(int a, int b) {
	return 
}

int main() {
	int N = 4;
	int W_MAX = 10;

	int k[4][2] = {
		{10, 5},
		{40, 4},
		{30, 6},
		{50, 3} 
	};

	
	int dp[5][11]; 

	
	for (int i = 0; i <= N; i++) {
		dp[i][0] = 0; 
	}
	for (int w = 0; w <= W_MAX; w++) {
		dp[0][w] = 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int w = 1; w <= W_MAX; w++) {

			if (k[i - 1][1] > w) {
				dp[i][w] = dp[i - 1][w];
			}
			else {
				dp[i][w] = (dp[i - 1][w] > dp[i - 1][w - k[i - 1][1]] + k[i - 1][0]) ? dp[i - 1][w] : dp[i - 1][w - k[i - 1][1]] + k[i - 1][0];
			}
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= W_MAX; j++) 
			printf("%4d", dp[i][j]);
		printf("\n");
	}
	return 0;
}