#include <iostream>
#include <algorithm>

#define INF 10000000

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int dist[100][100];
	int n, m;

	cin >> n >> m;

	fill(&dist[0][0], &dist[99][100], INF);
	for (int i = 0; i < n; i++) dist[i][i] = 0;

	for (int i = 0; i < m; i++) {
		int vf, vr, cost;
		cin >> vf >> vr >> cost;
		dist[vf - 1][vr - 1] = min(dist[vf - 1][vr - 1], cost);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == INF)
				cout << "0 ";
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}