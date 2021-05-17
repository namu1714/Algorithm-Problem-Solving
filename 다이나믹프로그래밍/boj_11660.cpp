#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int dp[1024][1024];
	int N, M, n;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int rowSum = 0;
		for (int j = 0; j < N; j++) {
			cin >> n;
			rowSum += n;
			if (i == 0)
				dp[i][j] = rowSum;
			else
				dp[i][j] = dp[i - 1][j] + rowSum;
		}
	}

	for (int k = 0; k < M; k++) {
		int x1, x2, y1, y2, sum;

		cin >> x1 >> y1 >> x2 >> y2;
		x1 -= 1; y1 -= 1; x2 -= 1; y2 -= 1;

		sum = dp[x2][y2];
		if (x1 > 0) sum -= dp[x1 - 1][y2];
		if (y1 > 0)	sum -= dp[x2][y1 - 1];
		if (x1 > 0 && y1 > 0) sum += dp[x1 - 1][y1 - 1];

		cout << sum << "\n";
	}
	return 0;
}