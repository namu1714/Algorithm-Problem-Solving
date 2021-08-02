#include <iostream>

using namespace std;

int gear[4][8];
int top[4] = { 0,0,0,0 };

void moveGear(int num, int dir, int prev) {
	if (num > 0 && prev > -1) {
		int	thisLeft = top[num] - 2;
		if (thisLeft < 0) thisLeft += 8;
		int left = top[num - 1] + 2;
		if (left >= 8) left -= 8;

		if (gear[num][thisLeft] != gear[num - 1][left])
			moveGear(num - 1, -dir, 1);
	}
	if (num < 3 && prev < 1) {
		int	thisRight = top[num] + 2;
		if (thisRight >= 8) thisRight -= 8;
		int right = top[num + 1] - 2;
		if (right < 0) right += 8;

		if (gear[num][thisRight] != gear[num + 1][right])
			moveGear(num + 1, -dir, -1);
	}

	top[num] -= dir;
	if (top[num] < 0) top[num] += 8;
	if (top[num] >= 8) top[num] -= 8;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int K, score = 0;
	string str;

	for (int i = 0; i < 4; i++) {
		cin >> str;
		for (int j = 0; j < 8; j++) {
			gear[i][j] = str[j] - '0';
		}
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		int gearNum, dir;
		cin >> gearNum >> dir;

		moveGear(gearNum - 1, dir, 0);
	}

	if (gear[0][top[0]] > 0) score += 1;
	if (gear[1][top[1]] > 0) score += 2;
	if (gear[2][top[2]] > 0) score += 4;
	if (gear[3][top[3]] > 0) score += 8;

	cout << score;

	return 0;
}