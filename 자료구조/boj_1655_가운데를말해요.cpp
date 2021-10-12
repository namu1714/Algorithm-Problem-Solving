#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, num;
	priority_queue<int, vector<int>, less<>> qDown;
	priority_queue<int, vector<int>, greater<>> qUp;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;

		if (qDown.empty() == true || qDown.top() >= num) {
			qDown.push(num);
		}
		else {
			qUp.push(num);
		}

		if (qUp.size() > qDown.size()) {
			qDown.push(qUp.top());
			qUp.pop();
		}
		if (qDown.size() > qUp.size() + 1) {
			qUp.push(qDown.top());
			qDown.pop();
		}

		cout << qDown.top() << "\n";
	}

	return 0;
}