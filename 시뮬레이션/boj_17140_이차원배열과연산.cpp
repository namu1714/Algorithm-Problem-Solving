#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int A[100][100] = { 0, };

int sortArray(char type, int n, int size) {
	vector<pair<int, int>> tmp(101); // 등장횟수, 수
	int newSize = 0;

	for (int i = 0; i <= 100; i++)
		tmp[i].second = i;

	if (type == 'r') {
		for (int i = 0; i < size; i++) {
			tmp[A[n][i]].first++;
		}
		sort(tmp.begin(), tmp.end());

		for (int i = 0; i <= 100; i++) {
			if (tmp[i].first == 0 || tmp[i].second == 0)
				continue;
			A[n][newSize] = tmp[i].second;
			A[n][newSize + 1] = tmp[i].first;
			newSize += 2;
			if (newSize >= 100) break;
		}
	}
	else if (type == 'c') {
		for (int i = 0; i < size; i++) {
			tmp[A[i][n]].first++;
		}
		sort(tmp.begin(), tmp.end());

		for (int i = 0; i <= 100; i++) {
			if (tmp[i].first == 0 || tmp[i].second == 0)
				continue;
			A[newSize][n] = tmp[i].second;
			A[newSize + 1][n] = tmp[i].first;
			newSize += 2;
			if (newSize >= 100) break;
		}
	}
	return newSize;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, c, k;
	int rowCnt = 3, colCnt = 3;

	cin >> r >> c >> k;

	for (int i = 0; i < rowCnt; i++) {
		for (int j = 0; j < colCnt; j++) {
			cin >> A[i][j];
		}
	}

	int second = 0;
	bool flag = false;

	while (second <= 100) {
		if (A[r - 1][c - 1] == k) {
			cout << second;
			flag = true;
			break;
		}

		int newSize, maxSize = 0;
		if (rowCnt >= colCnt) { //R 연산
			for (int i = 0; i < rowCnt; i++) {
				newSize = sortArray('r', i, colCnt);
				maxSize = max(maxSize, newSize);
				for (int j = newSize; j < 100; j++)
					A[i][j] = 0;
			}
			colCnt = maxSize;
		}
		else { //C 연산
			for (int i = 0; i < colCnt; i++) {
				newSize = sortArray('c', i, rowCnt);
				maxSize = max(maxSize, newSize);
				for (int j = newSize; j < 100; j++)
					A[j][i] = 0;
			}
			rowCnt = maxSize;
		}

		second++;
	}
	if (flag == false)
		cout << -1;

	return 0;
}