#include <iostream>
#include <numeric>

#define MOD 1000000007
typedef long long ll;

using namespace std;

ll mult(ll n, ll cnt) {
	if (cnt == 1) return n;
	if (cnt % 2 == 0) {
		ll tmp = mult(n, cnt / 2);
		return tmp * tmp % MOD;
	}
	else {
		return mult(n, cnt - 1) * n % MOD;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int M;
	ll N, S, sum = 0;

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> N >> S;

		//기약분수 
		ll div = gcd(N, S);
		N /= div;
		S /= div;

		sum += S * mult(N, MOD - 2) % MOD;
		sum %= MOD;
	}
	cout << sum;

	return 0;
}