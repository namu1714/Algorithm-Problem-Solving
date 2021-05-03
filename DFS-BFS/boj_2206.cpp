#include <stdio.h>
#include <queue>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

short map[1000][1000];
bool check[1000][1000][2]; //�湮 ����, �� ���� ����

typedef struct pos {
	int x, y;
	int num;
	bool isBreak;
};

int bfs(int N, int M) {
	queue<pos> q;
	q.push({ 0, 0, 1, false });
	check[0][0][0] = true;
	check[0][0][1] = false;

	while (!q.empty()) {
		pos p = q.front();
		q.pop();

		if (p.x == M - 1 && p.y == N - 1)
			return p.num;

		for (int i = 0; i < 4; i++) {
			int xx = p.x + dx[i];
			int yy = p.y + dy[i];

			if (xx < 0 || xx >= M || yy < 0 || yy >= N) continue;
			if (check[yy][xx][0] == true )

			if (map[yy][xx] == 0) { //�� �ƴ�
				if (p.isBreak && check[yy][xx][0] == false) {
					q.push({ xx, yy, p.num + 1, p.isBreak });
					check[yy][xx][0] = true;
					check[yy][xx][1] = p.isBreak;
				}
				else if (!p.isBreak && (check[yy][xx][1] == true || check[yy][xx][0] == false)) {
					q.push({ xx, yy, p.num + 1, p.isBreak });
					check[yy][xx][0] = true;
					check[yy][xx][1] = p.isBreak;
				}
			}
			else if (map[yy][xx] == 1 && !p.isBreak && check[yy][xx][0] == false) { //��
				q.push({ xx, yy, p.num + 1, true });
				check[yy][xx][0] = true;
				check[yy][xx][1] = true;

			}
		}
	}

	return -1;
}

int main() {
	int N, M, minRoute;
	char c;

	scanf("%d %d", &N, &M);

	scanf("%c", &c);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &c);
			map[i][j] = (int)c - '0';
			check[i][j][0] = false;
			check[i][j][1] = false;
		}
		scanf("%c", &c);
	}

	minRoute = bfs(N, M);

	if (minRoute < 0)
		printf("-1");
	else
		printf("%d", minRoute);

	return 0;
}