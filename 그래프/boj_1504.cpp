#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 10000000

using namespace std;

vector<pair<int, int>> graph[801];
int dist[3][801]; //1, Á¤Á¡, N

void djikstra(int n, int dCase) {
	priority_queue<pair<int, int>> pq;

	dist[dCase][n] = 0;
	pq.push({ 0, n });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int v = pq.top().second;
		pq.pop();

		if (dist[dCase][v] < cost) continue;

		for (pair<int, int> p : graph[v]) {
			if (dist[dCase][p.first] > dist[dCase][v] + p.second) {
				dist[dCase][p.first] = dist[dCase][v] + p.second;
				pq.push({ -dist[dCase][p.first], p.first });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, E, v1, v2;
	cin >> N >> E;

	int start, end, cost;
	for (int i = 0; i < E; i++) {
		cin >> start >> end >> cost;
		graph[start].push_back({ end, cost });
		graph[end].push_back({ start, cost });
	}
	cin >> v1 >> v2;

	fill(&dist[0][0], &dist[2][N + 1], INF);

	djikstra(1, 0);
	djikstra(v1, 1);
	djikstra(N, 2);

	int minRoute = min(dist[0][v1] + dist[1][v2] + dist[2][v2], dist[0][v2] + dist[1][v2] + dist[2][v1]);
	if (minRoute >= INF)
		cout << -1;
	else
		cout << minRoute;

	return 0;
}