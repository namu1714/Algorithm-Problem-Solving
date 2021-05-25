#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int graph[100][100];
bool air[100][100];
bool delCheese[100][100];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void airDFS(int n, int m) {
	air[n][m] = true;

	for (int i = 0; i < 4; i++) {
		int yy = n + dy[i];
		int xx = m + dx[i];

		if (xx < 0 || xx >= M || yy < 0 || yy >= N) continue;
		if (graph[yy][xx] == 1) continue;
		if (air[yy][xx] == true) continue;

		airDFS(yy, xx);
	}
}

int removeCheck() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) continue;
			int touchAir = 0;

			for (int k = 0; k < 4; k++) {
				if (air[i + dy[k]][j + dx[k]] == true)
					touchAir++;
			}

			if (touchAir >= 2) {
				delCheese[i][j] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int cheeseCnt = 0, time = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1)
				cheeseCnt++;
		}
	}

	while (cheeseCnt > 0) {
		memset(air, 0, sizeof(air));
		memset(delCheese, 0, sizeof(delCheese));
		airDFS(0, 0);
		cheeseCnt -= removeCheck();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (delCheese[i][j] == true)
					graph[i][j] = 0;
			}
		}
		time++;
	}

	cout << time;

	return 0;
}