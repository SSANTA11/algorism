// 최소 신장 트리
	// 가중치 고려 신장트리
		// 신장트리: 사이클 없이 모든 정점이 연결된 케이스

// 탐욕(Greedy) 알고리즘

	// 최소 신장 트리	

		// TIP!! 시험준비 포인트
			// 그래프를 두고 BFS, DFS, 크루스칼, 프림 등의 알고리즘 순서 맞추기

	// 최단 경로
		// 주어진 가중치 그래프에서 어느 한 출발점에서 또 다른 도착점까지의 최단 경로를 찾는 문제
		// 즉, 반드시 경유하는 정점을 고려해야함
		// 최단 경로를 찾는 대표적인 알고리즘
			// 다익스트라 알고리즘
				// ppt 참고
				// 서울만 고려한버전, 천안 또한 고려한 버전

#include <stdio.h>

#define INF  10000           // 무한대 값
#define MAX_VERTICES 10	// 그래프의 정점 개수

int distance[MAX_VERTICES];	// 시작 정점으로부터의 최단 경로 길이 저장
bool S[MAX_VERTICES];		// 정점의 집합 S

int nextVertex(int n);
int printStep(int step);
void Dijkstra_shortestPath(int start, int n);

// 최소 거리를 갖는 다음 정점을 찾는 연산
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

// 최단 경로 구하는 과정을 출력하는 연산
// 서울A 원주B 강릉C 천안D 논산E 대전F 대구G 포항H 광주 부산J 
#define MAX_VERTICES 10
#define INF 10000 

int weight[MAX_VERTICES][MAX_VERTICES] = {
	//   A(서울) B(원주) C(강릉) D(천안) E(논산) F(대전) G(대구) H(포항) I(광주) J(부산)
		// 0. 서울 (A) - 입력 데이터 첫 두 줄 반영
		{ 0,    15,    INF,   12,    INF,   INF,   INF,   INF,   INF,   INF },
		// 1. 원주 (B) - 입력 데이터 두 번째 줄 반영
		{ 15,   0,     21,    INF,   INF,   INF,   7,     INF,   INF,   INF },
		// 2. 강릉 (C) - 이미지 기반
		{ INF,  21,    0,     INF,   INF,   INF,   INF,   25,    INF,   INF },
		// 3. 천안 (D) - 이미지 기반
		{ 12,   INF,   INF,   0,     4,     10,    INF,   INF,   INF,   INF },
		// 4. 논산 (E) - 이미지 기반
		{ INF,  INF,   INF,   4,     0,     3,     INF,   INF,   13,    INF },
		// ----------------------------------------------------------------------
		// 5. 대전 (F) - 이미지 기반 (천안, 논산, 대구와 연결)
		{ INF,  INF,   INF,   10,    3,     0,     10,    INF,   INF,   INF },
		// 6. 대구 (G) - 이미지 기반 (원주, 대전, 포항, 부산과 연결)
		{ INF,  7,     INF,   INF,   INF,   10,    0,     19,    INF,   9   },
		// 7. 포항 (H) - 이미지 기반 (강릉, 대구, 부산과 연결)
		{ INF,  INF,   25,    INF,   INF,   INF,   19,    0,     INF,   5   },
		// 8. 광주 (I) - 이미지 기반 (논산, 부산과 연결)
		{ INF,  INF,   INF,   INF,   13,    INF,   INF,   INF,   0,     15  },
		// 9. 부산 (J) - 이미지 기반 (대구, 포항, 광주와 연결)
		{ INF,  INF,   INF,   INF,   INF,   INF,   9,     5,     15,    0   }
};
int printStep(int step) {
	int i;
	printf("\n %3d 단계 : S={", step);
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
// [알고리즘 8-3] 구현
void Dijkstra_shortestPath(int start, int n) {
	int i, u, w, step = 0;

	for (i = 0; i < n; i++) {	// 초기화
		distance[i] = weight[start][i];
		S[i] = false;
	}

	S[start] = true;			// 시작 정점을 집합 S에 추가
	distance[start] = 0;		// 시작 정점의 최단경로를 0으로 설정

	step = printStep(0);		// 0단계 상태를 출력

	for (i = 0; i < n - 1; i++) {
		u = nextVertex(n);		// 최단 경로를 만드는 다음 정점 u 찾기
		S[u] = true;			// 정점 u를 집합 S에 추가
		for (w = 0; w < n; w++)
			if (!S[w])			// 집합 S에 포함되지 않은 정점 중에서
//---------------------------------------------------------------------##시험 출제 포인트###--------------------------------------------------------------------------------
				if (distance[u] + weight[u][w] < distance[w]) // 더 짧은 경로 발견
					// distance[u]: 시작부터 u까지의 경로 길이 -----------u에서 인접 w까지의 길이------------
					distance[w] = distance[u] + weight[u][w];	// 경로 길이 수정
//		변수, 의미하는 '값', 역할
//			u(정점), 현재 처리 중인 정점 자체, 우선순위 큐에서 시작점으로부터 최단 경로가 확정된 정점입니다.
//			distance[u], u까지의 최단 경로 길이, 시작점에서  u 까지 도달하는 데 걸리는 최소 비용입니다.
//			weight[u][w], u에서 w로 가는 비용, "u와 w를 잇는 간선 (u, w)의 **가중치 (Weight)**입니다."
////---------------------------------------------------------------------##시험 출제 포인트###--------------------------------------------------------------------------------

		step = printStep(step);	// 현재 단계 출력
	}
}

int main(void) {
	int i, j;
	extern int weight[MAX_VERTICES][MAX_VERTICES];

	printf("\n ********** 가중치 인접 행렬 **********\n\n");
	for (i = 0; i < MAX_VERTICES; i++) {
		for (j = 0; j < MAX_VERTICES; j++) {
			if (weight[i][j] == INF)
				printf("%4c", '*');
			else printf("%4d", weight[i][j]);
		}
		printf("\n\n");
	}

	printf("\n ********* 다익스트라 최단 경로 구하기 **********\n");
	Dijkstra_shortestPath(0, MAX_VERTICES);

	getchar();  return 0;
}