#include <iostream>
#include <algorithm>

#define INF 100000
using namespace std;

int region[100][100];
int item[100];

void bellmanFord(int n) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				region[i][j] = min(region[i][j], region[i][k] + region[k][j]);
			}
		}
	}
}

int getItem(int n, int point, int range) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (region[point][i] <= range)
			sum += item[i];
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m, r;
	int maxItem = 0;

	cin >> n >> m >> r;

	fill(&region[0][0], &region[n - 1][n], INF);

	for (int i = 0; i < n; i++) {
		cin >> item[i];
		region[i][i] = 0;
	}
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		region[a - 1][b - 1] = l;
		region[b - 1][a - 1] = l;
	}
	bellmanFord(n);

	for (int i = 0; i < n; i++) {
		maxItem = max(maxItem, getItem(n, i, m));
	}
	cout << maxItem;

	return 0;
}