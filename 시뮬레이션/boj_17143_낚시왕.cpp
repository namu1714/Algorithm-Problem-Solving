#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct shark {
	int size;
	int speed;
	int direction;
};

//위, 아래, 오른쪽, 왼쪽
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };

int R, C, M;
vector<vector<int>> map(100, vector<int>(100, -1));
vector<shark> sharks;

void moveShark(int r, int c, int snum, vector<vector<int>>& newMap) {
	shark s = sharks[snum];
	int dir = s.direction;
	int xx, yy;

	int toEnd;

	if (dir == 0) toEnd = r;
	else if (dir == 1) toEnd = R - r - 1;
	else if (dir == 2) toEnd = C - c - 1;
	else			   toEnd = c;

	if (toEnd >= s.speed) {
		xx = c + s.speed * dx[dir];
		yy = r + s.speed * dy[dir];
	}
	else {
		int dist = s.speed - toEnd;
		int changeDirCnt, remains;
		int width;

		if (dir == 0 || dir == 1)//상하 이동
			width = R - 1;
		else //좌우 이동
			width = C - 1;

		changeDirCnt = dist / width + 1;
		remains = dist % width;

		if (changeDirCnt % 2 > 0) {
			if (dir == 0) dir = 1;
			else if (dir == 1) dir = 0;
			else if (dir == 2) dir = 3;
			else			   dir = 2;
		}

		if (dir == 0) { // 상
			xx = c;
			yy = R - 1;
		}
		else if (dir == 1) { //하
			xx = c;
			yy = 0;
		}
		else if (dir == 2) { //우
			xx = 0;
			yy = r;
		}
		else { //좌
			xx = C - 1;
			yy = r;
		}
		xx += remains * dx[dir];
		yy += remains * dy[dir];
	}
	sharks[snum].direction = dir;

	if (newMap[yy][xx] >= 0) {
		shark s2 = sharks[newMap[yy][xx]];
		if (s2.size < s.size)
			newMap[yy][xx] = snum;
	}
	else {
		newMap[yy][xx] = snum;
	}
}

void moveSharks() {
	vector<vector<int>> newMap(100, vector<int>(100, -1));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] >= 0)
				moveShark(i, j, map[i][j], newMap);
		}
	}
	copy(newMap.begin(), newMap.end(), map.begin());
}

int catchShark(int col) {
	for (int i = 0; i < R; i++) {
		if (map[i][col] >= 0) {
			int sharkNum = map[i][col];
			map[i][col] = -1;
			return sharks[sharkNum].size;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		map[r - 1][c - 1] = i;
		sharks.push_back({ z, s, d - 1 });
	}

	int totalSize = 0;

	for (int i = 0; i < C; i++) {
		totalSize += catchShark(i);
		moveSharks();
	}
	cout << totalSize;

	return 0;
}