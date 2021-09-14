#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, K;
	int arr[301][301] = { 0, };

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			arr[i][j] += arr[i - 1][j];
			arr[i][j] += arr[i][j - 1];
			arr[i][j] -= arr[i - 1][j - 1];
		}
	}

	int r1, c1, r2, c2, sum;
	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> r1 >> c1 >> r2 >> c2;

		sum = arr[r2][c2];
		sum -= arr[r1 - 1][c2];
		sum -= arr[r2][c1 - 1];
		sum += arr[r1 - 1][c1 - 1];

		cout << sum << "\n";
	}
	return 0;
}