#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000
using namespace std;

struct compare {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		return a.second > b.second;
	}
};

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(0);

	int V, E;
	int K;

	vector<pair<int, int>> v[20001];
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	bool check[20001] = { 0, };
	int distance[20001];

	cin >> V >> E;
	cin >> K;

	int v1, v2, cost;
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2 >> cost;
		v[v1].push_back({ v2, cost });
	}

	for (int i = 1; i <= V; i++)
		distance[i] = INF;
	distance[K] = 0;

	int checkV = 0;
	pq.push({ K, 0 });

	while(!pq.empty()) {
		int minV = pq.top().first;
		int minDist = pq.top().second;
		pq.pop();

		if (check[minV] || minDist > distance[minV]) continue;

		check[minV] = true;
		if (++checkV == V) break;

		for (int i = 0; i < v[minV].size(); i++) {
			v2 = v[minV][i].first;
			cost = v[minV][i].second;

			if (check[v2]) continue;
			if (distance[minV] + cost < distance[v2]) {
				distance[v2] = distance[minV] + cost;
				pq.push({ v2, distance[v2] });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (distance[i] == INF)
			cout << "INF" << "\n";
		else
			cout << distance[i] << "\n";
	}

	return 0;
}