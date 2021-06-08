#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	vector<int> v;
	int N, M, B;
	int height, minTime = 100000000;

	cin >> N >> M >> B;

	for (int i = 0; i < N * M; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), greater<>());

	for (int i = v[0]; i >= v[N * M - 1]; i--) {
		int time = 0;
		int blocks = B;

		for (int j = 0; j < N * M; j++) {
			int move = v[j] - i;
			blocks += move;

			if (move > 0) time += move * 2;
			else if (move < 0) time += (-move) * 1;

			if (blocks < 0) break;
			if (time > minTime) break;
		}
		if (blocks >= 0 && time < minTime) {
			minTime = time;
			height = i;
		}
	}

	cout << minTime << " " << height;

	return 0;
}