#include <iostream>
#include <queue>

#define APPLE 1
#define SNAKE 2

using namespace std;

enum Direction { LEFT, RIGHT, UP, DOWN };
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

queue<pair<int, char>> dirChange;
int board[100][100] = { 0, };

int simulation(int N) {
	int time = 1;
	Direction dir = RIGHT;
	queue<pair<int, int>> snakes;

	snakes.push({ 0,0 });
	board[0][0] = SNAKE;

	while (true) {
		int yy = snakes.back().first + dy[dir];
		int xx = snakes.back().second + dx[dir];

		if (yy >= N || yy < 0 || xx >= N || xx < 0)
			break;

		if (board[yy][xx] == SNAKE)
			break;

		if (board[yy][xx] != APPLE) {
			board[snakes.front().first][snakes.front().second] = 0;
			snakes.pop();
		}
		snakes.push({ yy,xx });
		board[yy][xx] = SNAKE;

		if (!dirChange.empty() && dirChange.front().first == time) {
			char change = dirChange.front().second;
			dirChange.pop();

			switch (dir) {
			case LEFT:
				if (change == 'L') dir = DOWN;
				else if (change == 'D') dir = UP;
				break;
			case RIGHT:
				if (change == 'L') dir = UP;
				else if (change == 'D') dir = DOWN;
				break;
			case UP:
				if (change == 'L') dir = LEFT;
				else if (change == 'D') dir = RIGHT;
				break;
			case DOWN:
				if (change == 'L') dir = RIGHT;
				else if (change == 'D') dir = LEFT;
				break;
			}
		}
		time++;
	}

	return time;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, K, L;

	cin >> N;

	cin >> K;
	for (int i = 0; i < K; i++) {
		int col, row;
		cin >> row >> col;
		board[row - 1][col - 1] = APPLE;
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		int sec;
		char dir;
		cin >> sec >> dir;
		dirChange.push({ sec, dir });
	}

	cout << simulation(N);

	return 0;
}