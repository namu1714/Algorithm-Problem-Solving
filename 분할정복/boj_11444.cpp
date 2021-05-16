#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix base = { {1,1}, {1,0} };

matrix mult(matrix a, matrix b) {
	matrix m = { {0,0},{0,0} };
	m[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
	m[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
	m[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
	m[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
	return m;
}

matrix fibo(ll n) {
	if (n == 1) return base;

	if (n % 2 == 0) {
		matrix tmp = fibo(n / 2);
		return mult(tmp, tmp);
	}
	else {
		matrix tmp = fibo(n - 1);
		return mult(tmp, base);
	}
}

int main() {
	ll n;
	cin >> n;

	matrix m = fibo(n);
	printf("%lld", m[1][0]);

	return 0;
}