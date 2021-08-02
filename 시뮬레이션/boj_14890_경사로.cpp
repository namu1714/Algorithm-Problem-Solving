#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int line[100];
bool check[100];
int L, N;

bool checkSlope(int x, int dx) {
	int height = line[x];
	int xx = x;

	for (int cnt = 0; cnt < L; cnt++) {
		if (xx < 0 || xx >= N)
			return false;
		if (line[xx] != height)
			return false;
		if (check[xx] == true)
			return false;
		xx += dx;
	}

	xx = x;
	for (int cnt = 0; cnt < L; cnt++) {
		check[xx] = true;
		xx += dx;
	}
	return true;
}

bool checkRoute() {
	for (int i = 1; i < N; i++) {
		if (line[i] == line[i - 1]) {
			continue;
		}
		else if (abs(line[i] - line[i - 1]) > 1) {
			return false;
		}
		else {
			if (line[i] > line[i - 1]) {
				if (!checkSlope(i - 1, -1)) return false;
			}
			else {
				if (!checkSlope(i, 1)) return false;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int answer = 0;
	int map[100][100];

	cin >> N >> L;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++) { //가로
		memset(check, 0, sizeof(check));
		for (int j = 0; j < N; j++) {
			line[j] = map[i][j];
		}
		if (checkRoute() == true)
			answer++;
	}

	for (int i = 0; i < N; i++) { //세로
		memset(check, 0, sizeof(check));
		for (int j = 0; j < N; j++) {
			line[j] = map[j][i];
		}
		if (checkRoute() == true)
			answer++;
	}

	cout << answer;

	return 0;
}