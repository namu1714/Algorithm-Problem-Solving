#include <iostream>
using namespace std;

int matrix[64][64];

int isSameNum(int n, int row, int col) {
	int num = matrix[row][col];

	for (int i = row; i < row + n; i++) {
		for (int j = col; j < col + n; j++) {
			if (matrix[i][j] != num)
				return -1;
		}
	}
	return num;
}

void quadTree(int n, int row, int col) {
	if (n == 1) {
		cout << matrix[row][col];
		return;
	}

	int num = isSameNum(n, row, col);
	if (num > -1) {
		cout << num;
		return;
	}

	cout << "(";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			quadTree(n / 2, row + n / 2 * i, col + n / 2 * j);
		}
	}
	cout << ")";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N;
	string str;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++)
			matrix[i][j] = str[j] - '0';
	}

	quadTree(N, 0, 0);

	return 0;
}