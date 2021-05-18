#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<pair<int, int>> v;
	int dp[100][100001] = { 0, };
	int N, K, W, V;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> W >> V;
		v.push_back({ W, V });
	}

	for (int i = v[0].first; i <= K; i++)
		dp[0][i] = v[0].second;

	for (int i = 1; i < N; i++) {
		int weight = v[i].first;
		int profit = v[i].second;

		for (int j = 0; j <= K; j++) {
			if (weight > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + profit);
		}
	}

	printf("%d", dp[N - 1][K]);

	return 0;
}