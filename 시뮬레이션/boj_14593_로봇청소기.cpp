#include <iostream>

using namespace std;

int dx[4] = { -1,0,1,0 }; //ºÏ¼­³²µ¿
int dy[4] = { 0,-1,0,1 };

int N, M;
int map[50][50];
bool check[50][50] = { 0, };

int clean(int r, int c, int dir) {
	int cnt = 0;

	while (true) {
		bool flag = false;

		if (check[r][c] == false) {
			check[r][c] = true;
			cnt++;
		}

		for (int i = 1; i <= 4; i++) {
			int nextDir = (dir + i) % 4;
			int nextR = r + dx[nextDir];
			int nextC = c + dy[nextDir];

			if (map[nextR][nextC] == 0 && check[nextR][nextC] == false) {
				flag = true;
				dir = nextDir;
				r = nextR; c = nextC;
				break;
			}
		}
		if (flag == false) {
			int backR = r - dx[dir];
			int backC = c - dy[dir];

			if (map[backR][backC] == 1) break;
			r = backR; c = backC;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int r, c, dir;

	cin >> N >> M;
	cin >> r >> c >> dir;

	if (dir == 1) dir = 3;
	else if (dir == 3) dir = 1;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	cout << clean(r, c, dir);

	return 0;
}