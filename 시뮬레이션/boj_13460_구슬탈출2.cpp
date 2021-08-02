#include <iostream>
#include <queue>

using namespace std;

int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

typedef struct Position {
	pair<int, int> red;
	pair<int, int> blue;
	int cnt;
};

int board[10][10];
pair<int, int> hole;

void move(int dir, pair<int, int>& moveM, pair<int, int>& otherM) {
	int curY = moveM.first, curX = moveM.second;

	while (true) {
		int nextY = curY + dy[dir];
		int nextX = curX + dx[dir];

		if (board[nextY][nextX] == '#')
			break;
		if (board[nextY][nextX] == 'O') {
			curY = nextY, curX = nextX;
			break;
		}
		if (nextY == otherM.first && nextX == otherM.second)
			break;

		curY = nextY;
		curX = nextX;
	}
	moveM = { curY, curX };
}

int bfs(pair<int, int>& red, pair<int, int>& blue) {
	queue<Position> Q;

	Q.push({ red,blue,0 });

	while (!Q.empty()) {
		int cnt = Q.front().cnt;
		pair<int, int> redCur = Q.front().red;
		pair<int, int> blueCur = Q.front().blue;
		Q.pop();

		if (cnt >= 10) return -1;

		for (int i = 0; i < 4; i++) {
			pair<int, int> redNext(redCur);
			pair<int, int> blueNext(blueCur);

			bool redFirst = true;

			if ((i == 0 && redNext.second > blueNext.second) || (i == 1 && redNext.second < blueNext.second)
				|| (i == 2 && redNext.first > blueNext.first) || (i == 3 && redNext.first < blueNext.first))
				redFirst = false;

			if (redFirst == true) {
				move(i, redNext, blueNext);
				move(i, blueNext, redNext);
			}
			else {
				move(i, blueNext, redNext);
				move(i, redNext, blueNext);
			}

			if (blueNext == hole)
				continue;
			if (redNext == hole)
				return cnt + 1;

			if (redCur == redNext && blueCur == blueNext)
				continue;

			Q.push({ redNext, blueNext, cnt + 1 });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	char c;
	pair<int, int> red, blue;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> c;
			if (c == 'R') {
				red = { i,j };
				board[i][j] = '.';
			}
			else if (c == 'B') {
				blue = { i,j };
				board[i][j] = '.';
			}
			else if (c == 'O') {
				hole = { i,j };
				board[i][j] = 'O';
			}
			else {
				board[i][j] = c;
			}
		}
	}

	cout << bfs(red, blue);

	return 0;
}