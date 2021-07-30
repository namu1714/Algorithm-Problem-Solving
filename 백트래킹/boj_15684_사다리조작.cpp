#include <iostream>
#include <algorithm>

using namespace std;

int N, M, H;
int minLadder = 4;
int ladder[10][30];

bool ladderGame() {
	for (int i = 0; i < N; i++) {
		int line = i;
		for (int j = 0; j < H; j++) {
			if (ladder[line][j] >= 0) {
				line = ladder[line][j];
			}
		}
		if (i != line)
			return false;
	}
	return true;
}

void dfs(int depth, int n, int h) {
	if (ladderGame() == true) {
		minLadder = min(minLadder, depth);
		return;
	}

	if (depth >= 3 || depth >= minLadder - 1)
		return;

	for (int i = n; i < N - 1; i++) {
		for (int j = (i == n) ? h : 0; j < H; j++) {
			if (ladder[i][j] < 0 && ladder[i + 1][j] < 0) {
				ladder[i][j] = i + 1;
				ladder[i + 1][j] = i;
				dfs(depth + 1, i, j);
				ladder[i][j] = -1;
				ladder[i + 1][j] = -1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M >> H;

	fill(&ladder[0][0], &ladder[9][30], -1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ladder[b - 1][a - 1] = b;
		ladder[b][a - 1] = b - 1;
	}

	dfs(0, 0, 0);

	if (minLadder > 3)
		cout << -1;
	else
		cout << minLadder;

	return 0;
}