#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef struct pos {
	int x, y;
	int time;
};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int N;
int map[20][20];
bool check[20][20];
pair<int, int> babyShark;

int bfs(int row, int col, int size) {
	int minTime = -1;

	queue<pos> Q;
	pair<int, int> nextShark;
	bool flag = false;

	Q.push({ col, row, 0 });
	check[row][col] = true;

	while (!Q.empty()) {
		pos cur = Q.front();

		Q.pop();

		if (flag == true && cur.time > minTime)
			break;

		if (map[cur.y][cur.x] > 0 && map[cur.y][cur.x] < size) {
			minTime = cur.time;
			if (flag == false) {
				nextShark = { cur.y, cur.x };
				flag = true;
			}
			else {
				if (nextShark.first > cur.y ||
					nextShark.first == cur.y && nextShark.second > cur.x) {
					nextShark = { cur.y, cur.x };
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int xx = cur.x + dx[i];
			int yy = cur.y + dy[i];

			if (xx < 0 || xx >= N || yy < 0 || yy >= N)
				continue;
			if (map[yy][xx] > size) continue;
			if (check[yy][xx] == true) continue;

			check[yy][xx] = true;
			Q.push({ xx,yy,cur.time + 1 });
		}
	}

	if (flag == true) {
		map[nextShark.first][nextShark.second] = 0;
		babyShark = nextShark;
	}

	return minTime;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int second = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				babyShark = { i,j };
				map[i][j] = 0;
			}
		}
	}

	int size = 2;
	int fishCnt = 0;
	while (true) {
		memset(check, false, sizeof(check));

		int fishTime = bfs(babyShark.first, babyShark.second, size);
		if (fishTime < 0) {
			break;
		}
		second += fishTime;
		fishCnt++;

		if (fishCnt == size) {
			fishCnt = 0;
			size++;
		}
	}
	cout << second;

	return 0;
}