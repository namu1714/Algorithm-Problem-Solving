#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool check[20][20];

int maxNum = 0;

bool blockMoves(int n, int dir, int row, int col, int(&board)[20][20]) {
	bool isDoubled = false;
	int curX = col, curY = row;

	while (true) {
		int nextX = curX + dx[dir];
		int nextY = curY + dy[dir];

		if (nextX >= n || nextX < 0 || nextY >= n || nextY < 0)
			break;

		if (board[nextY][nextX] > 0) { //블럭이 있음
			if (board[row][col] == board[nextY][nextX] && !check[nextY][nextX]) {
				board[nextY][nextX] = board[row][col] * 2;
				board[row][col] = 0;
				check[nextY][nextX] = true;
				isDoubled = true;
			}
			break;
		}
		curX = nextX;
		curY = nextY;
	}
	if (!isDoubled && col == curX && row == curY) //블럭이 이동하지 않음
		return false;

	if (!isDoubled) {
		board[curY][curX] = board[row][col];
		board[row][col] = 0;
	}
	return true;
}

void move2048(int n, int cnt, int dir, int(&board)[20][20]) {
	int moves = 0;

	memset(check, 0, sizeof(check));

	if (dir == 0) { //UP
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (board[j][i] > 0)
					if (blockMoves(n, dir, j, i, board)) moves++;
	}
	else if (dir == 1) { //DOWN
		for (int i = 0; i < n; i++)
			for (int j = n - 1; j >= 0; j--)
				if (board[j][i] > 0)
					if (blockMoves(n, dir, j, i, board)) moves++;
	}
	else if (dir == 2) { //LEFT
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] > 0)
					if (blockMoves(n, dir, i, j, board)) moves++;
	}
	else { //RIGHT
		for (int i = 0; i < n; i++)
			for (int j = n - 1; j >= 0; j--)
				if (board[i][j] > 0)
					if (blockMoves(n, dir, i, j, board)) moves++;
	}

	if (moves == 0 || cnt == 5) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				maxNum = max(maxNum, board[i][j]);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int boardCopy[20][20];
		copy(&board[0][0], &board[0][0] + 20 * 20, &boardCopy[0][0]);
		move2048(n, cnt + 1, i, boardCopy);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N;
	int board[20][20];

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int i = 0; i < 4; i++) {
		int boardCopy[20][20];
		copy(&board[0][0], &board[0][0] + 20 * 20, &boardCopy[0][0]);
		move2048(N, 1, i, boardCopy);
	}

	cout << maxNum;

	return 0;
}