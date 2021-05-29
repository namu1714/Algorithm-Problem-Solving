#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;

int N;
matrix origin(5);

matrix mulMatrix(matrix a, matrix b) {
	matrix m(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			m[i].push_back(0);
			for (int k = 0; k < N; k++) {
				m[i][j] += (a[i][k] * b[k][j]);
				m[i][j] %= 1000;
			}
		}
	}
	return m;
}

matrix squareMatrix(long long n) {
	if (n == 1) return origin;
	if (n % 2 == 0) {
		matrix m = squareMatrix(n / 2);
		return mulMatrix(m, m);
	}
	else {
		matrix m = squareMatrix(n / 2);
		matrix tmp = mulMatrix(m, m);
		return mulMatrix(tmp, origin);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	long long B;

	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			origin[i].push_back(tmp % 1000);
		}
	}
	matrix ret = squareMatrix(B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}