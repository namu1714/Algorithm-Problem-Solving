#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

bool map[101][101] = { 0, };

void drawDragonCurve(int x, int y, int dir, int gen) {
	vector<int> v;

	map[y][x] = true;

	x += dx[dir];
	y += dy[dir];
	map[y][x] = true;
	v.push_back(dir);

	for (int i = 1; i <= gen; i++) {
		for (int k = v.size() - 1; k >= 0; k--) {
			int nextDir = (v[k] + 1) % 4;
			x += dx[nextDir];
			y += dy[nextDir];

			map[y][x] = true;
			v.push_back(nextDir);
		}
	}
}

int getDragonNum() {
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == true && map[i + 1][j] == true &&
				map[i][j + 1] == true && map[i + 1][j + 1] == true)
				cnt++;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		drawDragonCurve(x, y, d, g);
	}

	cout << getDragonNum();

	return 0;
}