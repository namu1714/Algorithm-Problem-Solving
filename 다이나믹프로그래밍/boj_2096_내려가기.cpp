#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, a, b, c;
	int minArr[2][3] = { 0, }, maxArr[2][3] = { 0, };

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		minArr[1][0] = a + min({ minArr[0][0], minArr[0][1] });
		minArr[1][1] = b + min({ minArr[0][0], minArr[0][1], minArr[0][2] });
		minArr[1][2] = c + min({ minArr[0][1], minArr[0][2] });
		maxArr[1][0] = a + max({ maxArr[0][0], maxArr[0][1] });
		maxArr[1][1] = b + max({ maxArr[0][0], maxArr[0][1], maxArr[0][2] });
		maxArr[1][2] = c + max({ maxArr[0][1], maxArr[0][2] });

		copy(minArr[1], minArr[1] + 3, minArr[0]);
		copy(maxArr[1], maxArr[1] + 3, maxArr[0]);
	}

	cout << max({ maxArr[1][0], maxArr[1][1], maxArr[1][2] }) << " ";
	cout << min({ minArr[1][0], minArr[1][1], minArr[1][2] });

	return 0;
}