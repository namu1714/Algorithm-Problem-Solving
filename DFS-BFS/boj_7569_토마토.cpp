#include <iostream>
#include <queue>

using namespace std;

typedef struct tomato {
	int h, n, m;
	int time;
};

int dx[6] = { 0,0,0,0,-1,1 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { -1,1,0,0,0,0 };

int M, N, H;
int box[100][100][100];

int getUnripeTomatoes() {
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[i][j][k] == 0) cnt++;
			}
		}
	}
	return cnt;
}

int ripeBfs() {
	queue<tomato> Q;
	int time;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[i][j][k] == 1)
					Q.push({ i, j, k, 0 });
			}
		}
	}

	while (!Q.empty()) {
		tomato t = Q.front();
		Q.pop();
		time = t.time;
		int z = t.h, y = t.n, x = t.m;

		for (int i = 0; i < 6; i++) {
			int zz = z + dz[i];
			int yy = y + dy[i];
			int xx = x + dx[i];

			if (xx < 0 || xx >= M || yy < 0 || yy >= N || zz < 0 || zz >= H)
				continue;

			if (box[zz][yy][xx] == 0) {
				box[zz][yy][xx] = 1;
				Q.push({ zz,yy,xx,time + 1 });
			}
		}
	}
	return time;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int remained, time;

	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++)
				cin >> box[i][j][k];

	remained = getUnripeTomatoes();
	if (remained == 0) {
		cout << 0;
	}
	else {
		time = ripeBfs();
		remained = getUnripeTomatoes();

		if (remained > 0)
			cout << -1;
		else
			cout << time;
	}

	return 0;
}