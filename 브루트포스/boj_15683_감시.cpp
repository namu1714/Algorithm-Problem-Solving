#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[4] = { 0,1,0,-1 }; //시계방향
int dy[4] = { -1,0,1,0 };

int N, M, minBlindSpot = 100;
vector<pair<int, int>> cameras;

int getBlindSpot(int map[][8]) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void fillMap(int row, int col, int dir, int map[][8]) {
	do {
		row += dy[dir];
		col += dx[dir];

		if (row < 0 || row >= N || col < 0 || col >= M)
			break;
		if (map[row][col] == 6)
			break;
		if (map[row][col] == 0)
			map[row][col] = -1;
	} while (true);
}

void dfs(int n, int map[][8]) {
	if (n == cameras.size()) {
		minBlindSpot = min(minBlindSpot, getBlindSpot(map));
		return;
	}
	int row = cameras[n].first;
	int col = cameras[n].second;
	int type = map[row][col];
	int copyMap[8][8];

	switch (type) {
	case 1:
		for (int i = 0; i < 4; i++) {
			copy(&map[0][0], &map[0][0] + 64, &copyMap[0][0]);
			fillMap(row, col, i, copyMap);
			dfs(n + 1, copyMap);
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++) {
			copy(&map[0][0], &map[0][0] + 64, &copyMap[0][0]);
			fillMap(row, col, i, copyMap);
			fillMap(row, col, i + 2, copyMap);
			dfs(n + 1, copyMap);
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			copy(&map[0][0], &map[0][0] + 64, &copyMap[0][0]);
			fillMap(row, col, i % 4, copyMap);
			fillMap(row, col, (i + 1) % 4, copyMap);
			dfs(n + 1, copyMap);
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			copy(&map[0][0], &map[0][0] + 64, &copyMap[0][0]);
			fillMap(row, col, i % 4, copyMap);
			fillMap(row, col, (i + 1) % 4, copyMap);
			fillMap(row, col, (i + 2) % 4, copyMap);
			dfs(n + 1, copyMap);
		}
		break;
	case 5:
		copy(&map[0][0], &map[0][0] + 64, &copyMap[0][0]);
		fillMap(row, col, 0, copyMap);
		fillMap(row, col, 1, copyMap);
		fillMap(row, col, 2, copyMap);
		fillMap(row, col, 3, copyMap);
		dfs(n + 1, copyMap);
		break;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int map[8][8];
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5)
				cameras.push_back({ i,j });
		}
	}

	dfs(0, map);

	cout << minBlindSpot;

	return 0;
}