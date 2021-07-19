#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M, answer = 0;
	string S;

	cin >> N >> M >> S;

	int start = 0;
	bool flag = true, ioi;
	while (start <= M - 2 * N - 1) {
		if (flag == true && start > 0) { //이전 문자열이 true
			if (S[start + 2 * N - 1] != 'O' || S[start + 2 * N] != 'I') {
				flag = false;
				start += 2 * N - 1;
			}
		}
		else {
			if (S[start] == 'O') {
				start += 1;
				flag = false;
				continue;
			}
			ioi = true, flag = true;
			for (int i = start; i < start + 2 * N + 1; i++) {
				if (ioi == true && S[i] == 'O' || ioi == false && S[i] == 'I') {
					start = i;
					flag = false;
					break;
				}
				ioi = !ioi;
			}
		}
		if (flag == true) {
			answer += 1;
			start += 2;
		}
	}
	cout << answer;

	return 0;
}