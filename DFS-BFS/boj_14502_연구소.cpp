#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int maxSafeZone = 0;
int map[8][8] = { 0, };
int virusMap[8][8];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int getSafeZone() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (virusMap[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void virusSpread(int row, int col) {
	virusMap[row][col] = 2;
	for (int i = 0; i < 4; i++) {
		int yy = row + dy[i];
		int xx = col + dx[i];
		if (yy < 0 || yy >= N || xx < 0 || xx >= M)
			continue;
		if (virusMap[yy][xx] == 0) {
			virusSpread(yy, xx);
		}
	}
}

void wallDfs(int cnt, int row, int col) {
	if (cnt == 3) {
		memcpy(virusMap, map, sizeof(map));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 2)
					virusSpread(i, j);
			}
		}
		maxSafeZone = max(maxSafeZone, getSafeZone());
		return;
	}
	for (int i = row; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == row && j < col) continue;
			if (map[i][j] == 0) {
				map[i][j] = 1;
				wallDfs(cnt + 1, i, j);
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	wallDfs(0, 0, 0);
	cout << maxSafeZone;

	return 0;
}