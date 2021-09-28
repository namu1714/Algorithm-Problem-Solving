#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M, tmp;
	vector<int> numbers;
	bool dp[2000][2000];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		numbers.push_back(tmp);
	}

	for (int i = 0; i < N; i++)
		dp[i][i] = true;

	for (int i = 0; i < N - 1; i++) {
		if (numbers[i] == numbers[i + 1])
			dp[i][i + 1] = true;
		else
			dp[i][i + 1] = false;
	}

	for (int i = 2; i < N; i++) {
		for (int j = 0; j + i < N; j++) {
			if (dp[j + 1][j + i - 1] == false) {
				dp[j][j + i] = false;
			}
			else {
				if (numbers[j] == numbers[j + i])
					dp[j][j + i] = true;
				else
					dp[j][j + i] = false;
			}
		}
	}

	cin >> M;
	int S, E;
	for (int i = 0; i < M; i++) {
		cin >> S >> E;

		if (dp[S - 1][E - 1] == true)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}