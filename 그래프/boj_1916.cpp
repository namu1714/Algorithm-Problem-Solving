#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	vector<pair<int, int>> cities[1001];
	int dist[1001];
	int N, M, A, B;

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int vf, vr, cost;
		cin >> vf >> vr >> cost;
		cities[vf].push_back({ vr, cost });
	}
	cin >> A >> B;

	fill_n(dist, N + 1, INF);
	dist[A] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, A });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int vv = pq.top().second;
		pq.pop();

		if (cost > dist[vv]) continue;
		if (vv == B) break;

		for (pair<int, int> p : cities[vv]) {
			if (cost + p.second < dist[p.first]) {
				dist[p.first] = cost + p.second;
				pq.push({ -dist[p.first], p.first });
			}
		}
	}

	printf("%d", dist[B]);

	return 0;
}