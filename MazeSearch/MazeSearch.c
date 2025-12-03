#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE_HEIGHT 7
#define SIZE_WIDTH 9

typedef struct Location {
	int x;
	int y;
} L;

int directionX[] = { 1, -1, 0, 0 };
int directionY[] = { 0, 0, 1, -1 };

char mazeArr[SIZE_HEIGHT][SIZE_WIDTH] = {
	{ '=','=','=','=','=','=','=','=','='},
	{ ' ',' ',' ',' ','=',' ',' ',' ','='},
	{ '=',' ','=','=','=',' ','=','=','='},
	{ '=',' ','=',' ',' ',' ',' ',' ','='},
	{ '=',' ','=',' ','=','=','=',' ','='},
	{ '=',' ',' ',' ',' ',' ','=',' ','e'},
	{ '=','=','=','=','=','=','=','=','='}
};

void showProgress(L position) {
	mazeArr[position.y][position.x] = 'x';

	printf("\n현재 위치: (%d, %d)\n", position.x, position.y);

	for (int y = 0; y < SIZE_HEIGHT; y++) {
		for (int x = 0; x < SIZE_WIDTH; x++) {
			printf("%c ", mazeArr[y][x]);
		}
		printf("\n");
	}
	printf("----------------------------------\n");
}

bool MazeSearch(L current) {
	mazeArr[current.y][current.x] = 'x';
	showProgress(current);

	for (int i = 0; i < 4; i++) {
		L next;
		next.x = current.x + directionX[i];
		next.y = current.y + directionY[i];

		if (next.x >= 0 && next.x < SIZE_WIDTH && next.y >= 0 && next.y < SIZE_HEIGHT) {
			if (mazeArr[next.y][next.x] == 'e') {
				showProgress(next);
				printf(" 목적지 도착\n");
				return true;
			}
			if (mazeArr[next.y][next.x] == ' ') {
				if (MazeSearch(next)) {
					return true;
				}
			}
		}
	}

	mazeArr[current.y][current.x] = ' ';
	printf("\n되돌아가기: (%d, %d)\n", current.x, current.y);
	return false;
}

int main() {
	L start = { 0, 1 };

	printf("시작 \n");
	MazeSearch(start);

}