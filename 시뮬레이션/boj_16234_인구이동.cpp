#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, L, R;
int country[50][50];
int check[50][50];
bool border[2][50][50]; //가로 세로

vector<pair<int, int>> cal;

bool openBorder() {
	bool flag = false;
	int differ;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j < N - 1) {
				differ = abs(country[i][j] - country[i][j + 1]);
				if (differ >= L && differ <= R) {
					border[0][i][j] = true;
					flag = true;
				}
			}
			if (i < N - 1) {
				differ = abs(country[i][j] - country[i + 1][j]);
				if (differ >= L && differ <= R) {
					border[1][i][j] = true;
					flag = true;
				}
			}
		}
	}
	return flag;
}

void dfs(int r, int c, int unionNum) {
	check[r][c] = unionNum;
	cal[unionNum].first++;
	cal[unionNum].second += country[r][c];

	if (c > 0) { //왼쪽
		if (border[0][r][c - 1] == true && check[r][c - 1] < 0)
			dfs(r, c - 1, unionNum);
	}
	if (c < N - 1) { //오른쪽 체크
		if (border[0][r][c] == true && check[r][c + 1] < 0)
			dfs(r, c + 1, unionNum);
	}
	if (r > 0) { //위쪽 체크
		if (border[1][r - 1][c] == true && check[r - 1][c] < 0)
			dfs(r - 1, c, unionNum);
	}
	if (r < N - 1) { //아래쪽 체크
		if (border[1][r][c] == true && check[r + 1][c] < 0)
			dfs(r + 1, c, unionNum);
	}
}

void movePopulation() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int unionNum = check[i][j];
			country[i][j] = cal[unionNum].second / cal[unionNum].first;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> country[i][j];
		}
	}

	int day = 0;
	while (true) {
		fill(&border[0][0][0], &border[1][49][50], false);
		fill(&check[0][0], &check[49][50], -1);
		cal.clear();

		if (openBorder() == false)
			break;

		int unionCnt = 0;

		//connected component 체크
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] < 0) {
					cal.push_back({ 0,0 });

					dfs(i, j, unionCnt);

					unionCnt++;
				}
			}
		}
		movePopulation();
		day++;
	}
	cout << day;

	return 0;
}