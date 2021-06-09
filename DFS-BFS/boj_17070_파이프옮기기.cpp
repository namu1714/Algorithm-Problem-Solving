#include <iostream>
#include <vector>

using namespace std;

enum Direction { VERTICAL, HORIZONTAL, DIAGONAL };
int house[16][16];
int N, totalCnt = 0;

void dfs(int row, int col, Direction dir) {
	if (row == N - 1 && col == N - 1) {
		totalCnt++;
		return;
	}
	if (dir != VERTICAL && col + 1 < N) { //가로 이동
		if (house[row][col + 1] == 0)
			dfs(row, col + 1, HORIZONTAL);
	}
	if (dir != HORIZONTAL && row + 1 < N) { //세로 이동
		if (house[row + 1][col] == 0)
			dfs(row + 1, col, VERTICAL);
	}
	if (col + 1 < N && row + 1 < N) {
		if (house[row][col + 1] == 0 && house[row + 1][col] == 0 && house[row + 1][col + 1] == 0)
			dfs(row + 1, col + 1, DIAGONAL);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> house[i][j];
		}
	}
	dfs(0, 1, HORIZONTAL);
	cout << totalCnt;

	return 0;
}