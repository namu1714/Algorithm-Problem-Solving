#include <iostream>
#include <queue>
#define INF 1000001

using namespace std;

int fast[INF] = { 0, };
int check[INF] = { 0, };

void bfs(int N, int K) {
	queue<pair<int, int>> Q;

	Q.push({ N, 0 });
	check[N] = 1;
	fast[N] = 0;

	while (!Q.empty()) {
		int cur = Q.front().first;
		int time = Q.front().second;
		Q.pop();

		if (cur == K) break;

		if (cur - 1 >= 0 && time + 1 <= fast[cur - 1]) {
			check[cur - 1] += check[cur];
			if (time + 1 < fast[cur - 1])
				Q.push({ cur - 1,time + 1 });
			fast[cur - 1] = time + 1;
		}
		if (cur + 1 < INF && time + 1 <= fast[cur + 1]) {
			check[cur + 1] += check[cur];
			if (time + 1 < fast[cur + 1])
				Q.push({ cur + 1, time + 1 });
			fast[cur + 1] = time + 1;
		}
		if (cur * 2 < INF && time + 1 <= fast[cur * 2]) {
			check[cur * 2] += check[cur];
			if (time + 1 < fast[cur * 2])
				Q.push({ cur * 2, time + 1 });
			fast[cur * 2] = time + 1;
		}
	}
}

int main() {
	int N, K;
	cin >> N >> K;

	fill_n(fast, INF, INF);
	bfs(N, K);

	cout << fast[K] << "\n";
	cout << check[K];

	return 0;
}