#include <iostream>
#include <vector>
#include <queue>

#define INF 100000001

using namespace std;

vector<pair<int, int>> cities[1001];
vector<int> route;
int before[1001];
int dist[1001];

void djikstra(int start, int dest) {
	priority_queue<pair<int, int>> pq;

	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int vv = pq.top().second;
		pq.pop();

		if (cost > dist[vv]) continue;
		if (vv == dest) break;

		for (pair<int, int>p : cities[vv]) {
			if (dist[p.first] > cost + p.second) {
				dist[p.first] = cost + p.second;
				before[p.first] = vv;
				pq.push({ -dist[p.first],p.first });
			}
		}
	}
	return;
}

void getRoute(int start, int dest) {
	int cur = dest;
	route.push_back(dest);
	while (cur != start) {
		route.push_back(before[cur]);
		cur = before[cur];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m, start, dest;

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int vf, vr, cost;
		cin >> vf >> vr >> cost;
		cities[vf].push_back({ vr,cost });
	}
	cin >> start >> dest;

	fill_n(dist, n + 1, INF);
	djikstra(start, dest);
	getRoute(start, dest);

	cout << dist[dest] << "\n";
	cout << route.size() << "\n";
	for (int i = route.size() - 1; i >= 0; i--)
		cout << route[i] << " ";

	return 0;
}