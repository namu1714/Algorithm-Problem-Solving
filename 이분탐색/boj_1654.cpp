#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, N;
	int line[10000];
	long long start, end, mid;

	cin >> K >> N;
	long long sum = 0;
	for (int i = 0; i < K; i++) {
		cin >> line[i];
		sum += line[i];
	}

	start = 1;
	end = sum / N;

	int cnt = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		cnt = 0;

		for (int i = 0; i < K; i++)
			cnt += (line[i] / mid);

		if (cnt < N)
			end = mid - 1;
		else
			start = mid + 1;
	}
	cout << end;

	return 0;
}