#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { 0,0,-1,1 }; //µ¿¼­ºÏ³²
int dy[4] = { 1,-1,0,0 };

int dice[6] = { 0, }; //À§, ºÏ, µ¿, ¼­, ³², ¾Æ·¡

void changeDice(int dir) {
	int tmp[6];
	copy(dice, dice + 6, tmp);

	if (dir == 0) { //µ¿
		dice[5] = tmp[2];
		dice[0] = tmp[3];
		dice[2] = tmp[0];
		dice[3] = tmp[5];
	}
	else if (dir == 1) { //¼­
		dice[5] = tmp[3];
		dice[0] = tmp[2];
		dice[2] = tmp[5];
		dice[3] = tmp[0];
	}
	else if (dir == 2) { //ºÏ
		dice[5] = tmp[1];
		dice[0] = tmp[4];
		dice[1] = tmp[0];
		dice[4] = tmp[5];
	}
	else { //³²
		dice[5] = tmp[4];
		dice[0] = tmp[1];
		dice[1] = tmp[5];
		dice[4] = tmp[0];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M, K, x, y;
	int map[20][20];


	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < K; i++) {
		int cmd, xx, yy;

		cin >> cmd;
		cmd -= 1;
		xx = x + dx[cmd];
		yy = y + dy[cmd];

		if (xx < 0 || xx >= N || yy < 0 || yy >= M)
			continue;

		changeDice(cmd);

		if (map[xx][yy] == 0) {
			map[xx][yy] = dice[5];
		}
		else {
			dice[5] = map[xx][yy];
			map[xx][yy] = 0;
		}

		cout << dice[0] << "\n";

		x = xx;
		y = yy;
	}

	return 0;
}