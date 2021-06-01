#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int arr[1000];
	int dp[1000][2] = { 0, };
	int N, maxSeq = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i][0] = max({ dp[i][0], dp[j][0] });
			}
			else if (arr[i] < arr[j]) {
				dp[i][1] = max({ dp[i][1], dp[j][0], dp[j][1] });
			}
		}
		dp[i][0]++;
		dp[i][1]++;
	}
	for (int i = 0; i < N; i++)
		maxSeq = max({ maxSeq, dp[i][0], dp[i][1] });
	cout << maxSeq;

	return 0;
}