#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

vector<int> trees[10][10];
int map[10][10];
int A[10][10];

void springSummer(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//spring
			sort(trees[i][j].begin(), trees[i][j].end());

			int dead = trees[i][j].size();
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] <= map[i][j]) {
					map[i][j] -= trees[i][j][k];
					trees[i][j][k]++;
				}
				else {
					dead = k;
					break;
				}
			}
			//summer
			for (int k = dead; k < trees[i][j].size(); k++) {
				map[i][j] += trees[i][j][k] / 2;
			}
			trees[i][j].erase(trees[i][j].begin() + dead, trees[i][j].end());
		}
	}
}

void autumn(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int treeCnt = 0;
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] % 5 == 0)
					treeCnt++;
			}
			if (treeCnt == 0) continue;

			for (int k = 0; k < 8; k++) {
				int xx = i + dx[k];
				int yy = j + dy[k];

				if (xx < 0 || xx >= N || yy < 0 || yy >= N)
					continue;

				for (int cnt = 0; cnt < treeCnt; cnt++)
					trees[xx][yy].push_back(1);
			}
		}
	}
}

void winter(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] += A[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M, K;

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			map[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int r, c, age;
		cin >> r >> c >> age;
		trees[r - 1][c - 1].push_back(age);
	}

	for (int i = 0; i < K; i++) {
		springSummer(N);
		autumn(N);
		winter(N);
	}

	int treeCnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			treeCnt += trees[i][j].size();
		}
	}
	cout << treeCnt;

	return 0;
}