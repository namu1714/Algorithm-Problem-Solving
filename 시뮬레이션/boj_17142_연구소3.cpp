#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_TIME 10000

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int N, M;
vector<vector<int>> map(50, vector<int>(50));
vector<pair<int, int>> virus;

int getSeconds(vector<vector<int>>& copyMap) {
	int sec = 0;
	for (int i = 0; i < virus.size(); i++)
		copyMap[virus[i].first][virus[i].second] = -3;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (copyMap[i][j] == -1)
				return -1;
			sec = max(sec, copyMap[i][j]);
		}
	}
	return sec;
}

int bfs(vector<int>& possible) {
	vector<vector<int>> copyMap(map);
	queue<pair<int, int>> Q;

	for (int i = 0; i < possible.size(); i++) {
		if (possible[i] == 1) {
			Q.push(virus[i]);
			copyMap[virus[i].first][virus[i].second] = 0;
		}
	}

	while (!Q.empty()) {
		int x = Q.front().second;
		int y = Q.front().first;
		int time = copyMap[y][x];

		Q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || xx >= N || yy < 0 || yy >= N)
				continue;

			if (copyMap[yy][xx] == -1 || copyMap[yy][xx] == -3) {
				copyMap[yy][xx] = time + 1;
				Q.push({ yy,xx });
			}
		}
	}
	return getSeconds(copyMap);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;

			map[i][j] = -tmp - 1;

			if (tmp == 2)
				virus.push_back({ i,j });
		}
	}

	vector<int> possible;
	for (int i = 0; i < virus.size() - M; i++)
		possible.push_back(0);
	for (int i = 0; i < M; i++)
		possible.push_back(1);

	int minTime = MAX_TIME;

	do {
		int time = bfs(possible);
		if (time >= 0) {
			minTime = min(time, minTime);
		}
	} while (next_permutation(possible.begin(), possible.end()));

	if (minTime == MAX_TIME)
		cout << -1;
	else
		cout << minTime;

	return 0;
}