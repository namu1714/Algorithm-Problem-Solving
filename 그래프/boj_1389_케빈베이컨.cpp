#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dist[100][100];

void floyd(int N) {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int getKebinBacon(int N) {
	int sum, minUser, minKevin = 1000;

	for (int i = 0; i < N; i++) {
		sum = 0;
		for (int j = 0; j < N; j++) {
			sum += dist[i][j];
		}
		if (sum < minKevin) {
			minKevin = sum;
			minUser = i + 1;
		}
	}
	return minUser;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M;

	cin >> N >> M;

	fill(&dist[0][0], &dist[99][100], 1000);
	for (int i = 0; i < N; i++)
		dist[i][i] = 0;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		dist[a - 1][b - 1] = 1;
		dist[b - 1][a - 1] = 1;
	}

	floyd(N);

	cout << getKebinBacon(N);

	return 0;
}