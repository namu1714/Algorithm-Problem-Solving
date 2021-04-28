#include <stdio.h>
#include <vector>

#define INF 10000000

using namespace std;

vector<pair<int, int>> v[501];
int dist[501];

void BellmanFord(int N) {
	for (int i = 0; i < N - 1; i++) { 	//N-1번 반복
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < v[j].size(); k++) {
				int u = v[j][k].first;
				if (dist[u] > dist[j] + v[j][k].second)
					dist[u] = dist[j] + v[j][k].second;
			}
		}
	}
}

int main() {
	int TC, N, M, W;
	int S, E, T;
	bool isCycle;

	scanf("%d", &TC);

	for (int t = 0; t < TC; t++) {
		scanf("%d %d %d", &N, &M, &W);

		for (int i = 1; i <= N; i++) { //그래프 초기화
			v[i].clear();
			dist[i] = INF;
		}

		for (int i = 0; i < M; i++) { //도로 입력
			scanf("%d %d %d", &S, &E, &T);
			v[S].push_back({ E, T });
			v[E].push_back({ S, T });
		}
		for (int i = 0; i < W; i++) { //웜홀 입력
			scanf("%d %d %d", &S, &E, &T);
			v[S].push_back({ E, -T });
		}

		BellmanFord(N);

		//음수사이클 체크
		isCycle = false;

		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < v[j].size(); k++) {
				int u = v[j][k].first;
				if (dist[u] > dist[j] + v[j][k].second) {
					dist[u] = dist[j] + v[j][k].second;
					isCycle = true;
				}
			}
		}

		if (isCycle)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}