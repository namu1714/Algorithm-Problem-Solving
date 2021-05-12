#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int T, n;
	int dp[2][100000];
	int score[2][100000];

	scanf("%d", &T);
	for (int k = 0; k < T; k++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &score[0][i]);
		for (int i = 0; i < n; i++) scanf("%d", &score[1][i]);

		dp[0][0] = score[0][0];
		dp[1][0] = score[1][0];
		if (n > 1) {
			dp[0][1] = dp[1][0] + score[0][1];
			dp[1][1] = dp[0][0] + score[1][1];
		}
		for (int i = 2; i < n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + score[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + score[1][i];
		}

		printf("%d\n", max(dp[0][n - 1], dp[1][n - 1]));
	}

	return 0;
}