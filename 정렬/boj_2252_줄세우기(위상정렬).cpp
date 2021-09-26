#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;

	vector<int> v[32001];
	queue<int> zeroDegree;
	int degree[32001] = { 0, };

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		degree[B]++;
	}

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0)
			zeroDegree.push(i);
	}

	vector<int> order;
	while (zeroDegree.empty() == false) {
		int cur = zeroDegree.front();
		zeroDegree.pop();
		order.push_back(cur);

		for (int next : v[cur]) {
			degree[next]--;
			if (degree[next] == 0)
				zeroDegree.push(next);
		}
	}

	for (int i = 0; i < order.size(); i++)
		cout << order[i] << " ";

	return 0;
}