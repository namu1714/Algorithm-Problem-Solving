#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 10000000
using namespace std;

vector<pair<int, int>> town[1001];
int dist[1001][1001];

void djikstra(int n, int dest) {
	priority_queue<pair<int, int>> pq;

	dist[n][n] = 0;
	pq.push({ 0, n });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int v = pq.top().second;
		pq.pop();

		if (dist[n][v] < cost) continue;

		if (v == dest) return;

		for (pair<int, int> p : town[v]) {
			if (dist[n][p.first] > dist[n][v] + p.second) {
				dist[n][p.first] = dist[n][v] + p.second;
				pq.push({ -dist[n][p.first], p.first });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M, X, maxTime = 0;
	cin >> N >> M >> X;

	int start, end, cost;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> cost;
		town[start].push_back({ end, cost });
	}

	fill(&dist[0][0], &dist[N][N + 1], INF);

	for (int i = 1; i <= N; i++)
		djikstra(i, X);
	djikstra(X, -1);

	for (int i = 1; i <= N; i++)
		maxTime = max(maxTime, dist[i][X] + dist[X][i]);

	printf("%d", maxTime);

	return 0;
}