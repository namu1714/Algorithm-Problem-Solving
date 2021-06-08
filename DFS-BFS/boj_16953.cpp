#include <iostream>
#include <queue>
using namespace std;

int bfs(long long A, long long B) {
	queue<pair<long long, int>> Q;
	Q.push({ A,0 });

	while (!Q.empty()) {
		long long num = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();

		if (num == B)
			return cnt + 1;
		if (num > B)
			continue;

		Q.push({ num * 2, cnt + 1 });
		Q.push({ num * 10 + 1, cnt + 1 });
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	long long A, B;
	cin >> A >> B;

	int answer = bfs(A, B);
	cout << answer;

	return 0;
}