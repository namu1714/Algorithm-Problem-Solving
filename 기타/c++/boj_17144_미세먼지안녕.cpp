#include <iostream>
#include <cstring>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int home[50][50];
int spreadTable[50][50];

int getTotalDust(int r, int c) {
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (home[i][j] == -1) continue;
			sum += home[i][j];
		}
	}
	return sum;
}

void spreadDust(int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int cnt = 0;
			if (home[i][j] <= 0) continue;

			for (int k = 0; k < 4; k++) {
				int yy = i + dy[k];
				int xx = j + dx[k];
				if (yy >= 0 && yy < r && xx >= 0 && xx < c && home[yy][xx] != -1) {
					cnt++;
					spreadTable[yy][xx] += home[i][j] / 5;
				}
			}
			spreadTable[i][j] += (home[i][j] - home[i][j] / 5 * cnt);
		}
	}
	memcpy(home, spreadTable, sizeof(home));
}

void cleanAir(int r, int c, int up, int down) {
	//위쪽 순환
	for (int i = up - 1; i > 0; i--) home[i][0] = home[i - 1][0];
	for (int i = 0; i < c - 1; i++) home[0][i] = home[0][i + 1];
	for (int i = 0; i < up; i++) home[i][c - 1] = home[i + 1][c - 1];
	for (int i = c - 1; i > 1; i--)home[up][i] = home[up][i - 1];
	home[up][1] = 0;
	//아래쪽 순환
	for (int i = down + 1; i < r - 1; i++) home[i][0] = home[i + 1][0];
	for (int i = 0; i < c - 1; i++) home[r - 1][i] = home[r - 1][i + 1];
	for (int i = r - 1; i > down; i--) home[i][c - 1] = home[i - 1][c - 1];
	for (int i = c - 1; i > 1; i--)home[down][i] = home[down][i - 1];
	home[down][1] = 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int R, C, T;
	int airCleaner = -1;

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> home[i][j];
			if (home[i][j] == -1 && airCleaner == -1)
				airCleaner = i;
		}
	}

	for (int i = 0; i < T; i++) {
		memset(spreadTable, 0, sizeof(spreadTable));
		spreadTable[airCleaner][0] = -1;
		spreadTable[airCleaner + 1][0] = -1;

		spreadDust(R, C);
		cleanAir(R, C, airCleaner, airCleaner + 1);
	}
	cout << getTotalDust(R, C);

	return 0;
}