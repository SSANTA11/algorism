// �ּ� ���� Ʈ��
	// ����ġ ��� ����Ʈ��
		// ����Ʈ��: ����Ŭ ���� ��� ������ ����� ���̽�

// Ž��(Greedy) �˰���

	// �ּ� ���� Ʈ��	

		// TIP!! �����غ� ����Ʈ
			// �׷����� �ΰ� BFS, DFS, ũ�罺Į, ���� ���� �˰��� ���� ���߱�

	// �ִ� ���
		// �־��� ����ġ �׷������� ��� �� ��������� �� �ٸ� ������������ �ִ� ��θ� ã�� ����
		// ��, �ݵ�� �����ϴ� ������ ����ؾ���
		// �ִ� ��θ� ã�� ��ǥ���� �˰���
			// ���ͽ�Ʈ�� �˰���
				// ppt ����
				// ���︸ ����ѹ���, õ�� ���� ����� ����

#include <stdio.h>

#define INF  10000           // ���Ѵ� ��
#define MAX_VERTICES 10	// �׷����� ���� ����

int distance[MAX_VERTICES];	// ���� �������κ����� �ִ� ��� ���� ����
bool S[MAX_VERTICES];		// ������ ���� S

int nextVertex(int n);
int printStep(int step);
void Dijkstra_shortestPath(int start, int n);

// �ּ� �Ÿ��� ���� ���� ������ ã�� ����
int nextVertex(int n) {
	int i, min, minPos;
	min = INF;
	minPos = -1;
	for (i = 0; i < n; i++)
		if ((distance[i] < min) && !S[i]) {
			min = distance[i];
			minPos = i;
		}
	return minPos;
}

// �ִ� ��� ���ϴ� ������ ����ϴ� ����
// ����A ����B ����C õ��D ���E ����F �뱸G ����H ���� �λ�J 
#define MAX_VERTICES 10
#define INF 10000 

int weight[MAX_VERTICES][MAX_VERTICES] = {
	//   A(����) B(����) C(����) D(õ��) E(���) F(����) G(�뱸) H(����) I(����) J(�λ�)
		// 0. ���� (A) - �Է� ������ ù �� �� �ݿ�
		{ 0,    15,    INF,   12,    INF,   INF,   INF,   INF,   INF,   INF },
		// 1. ���� (B) - �Է� ������ �� ��° �� �ݿ�
		{ 15,   0,     21,    INF,   INF,   INF,   7,     INF,   INF,   INF },
		// 2. ���� (C) - �̹��� ���
		{ INF,  21,    0,     INF,   INF,   INF,   INF,   25,    INF,   INF },
		// 3. õ�� (D) - �̹��� ���
		{ 12,   INF,   INF,   0,     4,     10,    INF,   INF,   INF,   INF },
		// 4. ��� (E) - �̹��� ���
		{ INF,  INF,   INF,   4,     0,     3,     INF,   INF,   13,    INF },
		// ----------------------------------------------------------------------
		// 5. ���� (F) - �̹��� ��� (õ��, ���, �뱸�� ����)
		{ INF,  INF,   INF,   10,    3,     0,     10,    INF,   INF,   INF },
		// 6. �뱸 (G) - �̹��� ��� (����, ����, ����, �λ�� ����)
		{ INF,  7,     INF,   INF,   INF,   10,    0,     19,    INF,   9   },
		// 7. ���� (H) - �̹��� ��� (����, �뱸, �λ�� ����)
		{ INF,  INF,   25,    INF,   INF,   INF,   19,    0,     INF,   5   },
		// 8. ���� (I) - �̹��� ��� (���, �λ�� ����)
		{ INF,  INF,   INF,   INF,   13,    INF,   INF,   INF,   0,     15  },
		// 9. �λ� (J) - �̹��� ��� (�뱸, ����, ���ֿ� ����)
		{ INF,  INF,   INF,   INF,   INF,   INF,   9,     5,     15,    0   }
};
int printStep(int step) {
	int i;
	printf("\n %3d �ܰ� : S={", step);
	for (i = 0; i < MAX_VERTICES; i++)
		if (S[i] == true)
			printf("%3c", i + 65);

	if (step < 1) 
		printf(" } \t\t\t");
	else if (step < 4) 
		printf(" } \t\t");
	else 
		printf(" } \t");
	printf(" distance :[ ");
	for (i = 0; i < MAX_VERTICES; i++)
		if (distance[i] == INF)
			printf("%4c", '*');
		else 
			printf("%4d", distance[i]);
	printf("%4c", ']');
	return ++step;
}
// [�˰��� 8-3] ����
void Dijkstra_shortestPath(int start, int n) {
	int i, u, w, step = 0;

	for (i = 0; i < n; i++) {	// �ʱ�ȭ
		distance[i] = weight[start][i];
		S[i] = false;
	}

	S[start] = true;			// ���� ������ ���� S�� �߰�
	distance[start] = 0;		// ���� ������ �ִܰ�θ� 0���� ����

	step = printStep(0);		// 0�ܰ� ���¸� ���

	for (i = 0; i < n - 1; i++) {
		u = nextVertex(n);		// �ִ� ��θ� ����� ���� ���� u ã��
		S[u] = true;			// ���� u�� ���� S�� �߰�
		for (w = 0; w < n; w++)
			if (!S[w])			// ���� S�� ���Ե��� ���� ���� �߿���
//---------------------------------------------------------------------##���� ���� ����Ʈ###--------------------------------------------------------------------------------
				if (distance[u] + weight[u][w] < distance[w]) // �� ª�� ��� �߰�
					// distance[u]: ���ۺ��� u������ ��� ���� -----------u���� ���� w������ ����------------
					distance[w] = distance[u] + weight[u][w];	// ��� ���� ����
//		����, �ǹ��ϴ� '��', ����
//			u(����), ���� ó�� ���� ���� ��ü, �켱���� ť���� ���������κ��� �ִ� ��ΰ� Ȯ���� �����Դϴ�.
//			distance[u], u������ �ִ� ��� ����, ����������  u ���� �����ϴ� �� �ɸ��� �ּ� ����Դϴ�.
//			weight[u][w], u���� w�� ���� ���, "u�� w�� �մ� ���� (u, w)�� **����ġ (Weight)**�Դϴ�."
////---------------------------------------------------------------------##���� ���� ����Ʈ###--------------------------------------------------------------------------------

		step = printStep(step);	// ���� �ܰ� ���
	}
}

int main(void) {
	int i, j;
	extern int weight[MAX_VERTICES][MAX_VERTICES];

	printf("\n ********** ����ġ ���� ��� **********\n\n");
	for (i = 0; i < MAX_VERTICES; i++) {
		for (j = 0; j < MAX_VERTICES; j++) {
			if (weight[i][j] == INF)
				printf("%4c", '*');
			else printf("%4d", weight[i][j]);
		}
		printf("\n\n");
	}

	printf("\n ********* ���ͽ�Ʈ�� �ִ� ��� ���ϱ� **********\n");
	Dijkstra_shortestPath(0, MAX_VERTICES);

	getchar();  return 0;
}