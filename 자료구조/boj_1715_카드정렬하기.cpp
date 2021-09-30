#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	priority_queue<int, vector<int>, greater<int>> q;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}

	int sum = 0;
	while (true) {
		int a = q.top();
		q.pop();

		if (q.empty() == true) break;

		int b = q.top();
		q.pop();

		sum += (a + b);
		q.push(a + b);
	}

	cout << sum;

	return 0;
}