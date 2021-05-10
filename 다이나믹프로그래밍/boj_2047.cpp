#include <stdio.h>
#include <math.h>

#define DIGITS 17

typedef long long ll;
typedef struct bigint {
	ll high;
	ll low;
};

bigint addBigint(bigint a, bigint b) {
	ll low = (a.low + b.low) % (ll)pow(10, DIGITS);
	ll high = (a.high + b.high) + (a.low + b.low) / (ll)pow(10, DIGITS);

	return bigint{ high, low };
}

int main() {
	int n, m;
	bigint dp[101][101];
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j > i) break;
			if (i == j || j == 0)
				dp[i][j] = { 0, 1 };
			else
				dp[i][j] = addBigint(dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}

	if (dp[n][m].high != 0)
		printf("%lld", dp[n][m].high);
	printf("%lld", dp[n][m].low);

	return 0;
}