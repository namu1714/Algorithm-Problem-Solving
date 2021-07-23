#include <iostream>
#include <queue>
using namespace std;

int check[10000];
char prevCmd[10000];

void bfs(int A, int B) {
	char cmds[4] = { 'D', 'S', 'L', 'R' };
	string tmp;
	char first, last;

	queue<int> Q;
	Q.push(A);

	while (!Q.empty()) {
		int nn, n = Q.front();
		Q.pop();

		for (char cmd : cmds) {
			switch (cmd) {
			case 'D':
				nn = n * 2;
				if (nn > 9999) nn %= 10000;
				break;
			case 'S':
				nn = n - 1;
				if (nn < 0) nn = 9999;
				break;
			case 'L':
				nn = n % 1000 * 10 + n / 1000;
				break;
			case 'R':
				nn = n % 10 * 1000 + n / 10;
				break;
			}
			if (check[nn] >= 0) continue;

			prevCmd[nn] = cmd;
			check[nn] = n;

			if (nn == B) return;

			Q.push(nn);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T, A, B;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;

		fill_n(check, 10000, -1);
		bfs(A, B);

		int n = B;
		string history = "";
		while (n != A) {
			history += prevCmd[n];
			n = check[n];
		}

		for (int i = history.size() - 1; i >= 0; i--)
			cout << history[i];
		cout << "\n";
	}

	return 0;
}