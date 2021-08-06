#include <iostream>

using namespace std;

char cube[6][3][3]; //위, 아래, 앞, 뒤, 왼, 오른

void initCube() {
	char initColor[6] = { 'w','y','r','o','g','b' };

	for (int k = 0; k < 6; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cube[k][i][j] = initColor[k];
			}
		}
	}
}

void printCubeTop() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[0][i][j];
		}
		cout << "\n";
	}
}

void turnThisPlane(char pChar, char dir) {
	char planes[6] = { 'U', 'D', 'F','B','L','R' };
	int p;

	for (int i = 0; i < 6; i++) {
		if (pChar == planes[i]) {
			p = i;
			break;
		}
	}

	char tmp1 = cube[p][0][2];
	char tmp2 = cube[p][0][1];

	if (dir == '+') { //시계방향
		cube[p][0][2] = cube[p][0][0];
		cube[p][0][1] = cube[p][1][0];
		cube[p][0][0] = cube[p][2][0];
		cube[p][1][0] = cube[p][2][1];
		cube[p][2][0] = cube[p][2][2];
		cube[p][2][1] = cube[p][1][2];
		cube[p][2][2] = tmp1;
		cube[p][1][2] = tmp2;
	}
	else { //반시계방향
		cube[p][0][1] = cube[p][1][2];
		cube[p][0][2] = cube[p][2][2];
		cube[p][1][2] = cube[p][2][1];
		cube[p][2][2] = cube[p][2][0];
		cube[p][2][1] = cube[p][1][0];
		cube[p][2][0] = cube[p][0][0];
		cube[p][1][0] = tmp2;
		cube[p][0][0] = tmp1;
	}
}

void turnCube(int p, char dir) {
	char tmp[3];
	switch (p) {
	case 'U':
		tmp[0] = cube[3][0][0];
		tmp[1] = cube[3][0][1];
		tmp[2] = cube[3][0][2];
		if (dir == '+') {
			for (int i = 0; i < 3; i++) cube[3][0][i] = cube[4][0][i];
			for (int i = 0; i < 3; i++) cube[4][0][i] = cube[2][0][i];
			for (int i = 0; i < 3; i++) cube[2][0][i] = cube[5][0][i];
			for (int i = 0; i < 3; i++) cube[5][0][i] = tmp[i];
		}
		else {
			for (int i = 0; i < 3; i++) cube[3][0][i] = cube[5][0][i];
			for (int i = 0; i < 3; i++) cube[5][0][i] = cube[2][0][i];
			for (int i = 0; i < 3; i++) cube[2][0][i] = cube[4][0][i];
			for (int i = 0; i < 3; i++) cube[4][0][i] = tmp[i];
		}
		break;
	case 'D':
		tmp[0] = cube[3][2][0];
		tmp[1] = cube[3][2][1];
		tmp[2] = cube[3][2][2];
		if (dir == '+') {
			for (int i = 0; i < 3; i++) cube[3][2][i] = cube[5][2][i];
			for (int i = 0; i < 3; i++) cube[5][2][i] = cube[2][2][i];
			for (int i = 0; i < 3; i++) cube[2][2][i] = cube[4][2][i];
			for (int i = 0; i < 3; i++) cube[4][2][i] = tmp[i];
		}
		else {
			for (int i = 0; i < 3; i++) cube[3][2][i] = cube[4][2][i];
			for (int i = 0; i < 3; i++) cube[4][2][i] = cube[2][2][i];
			for (int i = 0; i < 3; i++) cube[2][2][i] = cube[5][2][i];
			for (int i = 0; i < 3; i++) cube[5][2][i] = tmp[i];
		}
		break;
	case 'F':
		tmp[0] = cube[0][2][0];
		tmp[1] = cube[0][2][1];
		tmp[2] = cube[0][2][2];
		if (dir == '+') {
			for (int i = 0; i < 3; i++) cube[0][2][i] = cube[4][2 - i][2];
			for (int i = 0; i < 3; i++) cube[4][i][2] = cube[1][2][2 - i];
			for (int i = 0; i < 3; i++) cube[1][2][i] = cube[5][i][0];
			for (int i = 0; i < 3; i++) cube[5][i][0] = tmp[i];
		}
		else {
			for (int i = 0; i < 3; i++) cube[0][2][i] = cube[5][i][0];
			for (int i = 0; i < 3; i++) cube[5][i][0] = cube[1][2][i];
			for (int i = 0; i < 3; i++) cube[1][2][2 - i] = cube[4][i][2];
			for (int i = 0; i < 3; i++) cube[4][i][2] = tmp[2 - i];
		}
		break;
	case 'B':
		tmp[0] = cube[0][0][0];
		tmp[1] = cube[0][0][1];
		tmp[2] = cube[0][0][2];
		if (dir == '+') {
			for (int i = 0; i < 3; i++) cube[0][0][i] = cube[5][i][2];
			for (int i = 0; i < 3; i++) cube[5][i][2] = cube[1][0][i];
			for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[4][i][0];
			for (int i = 0; i < 3; i++) cube[4][i][0] = tmp[2 - i];
		}
		else {
			for (int i = 0; i < 3; i++) cube[0][0][i] = cube[4][2 - i][0];
			for (int i = 0; i < 3; i++) cube[4][i][0] = cube[1][0][2 - i];
			for (int i = 0; i < 3; i++) cube[1][0][i] = cube[5][i][2];
			for (int i = 0; i < 3; i++) cube[5][i][2] = tmp[i];
		}
		break;
	case 'L':
		tmp[0] = cube[0][0][0];
		tmp[1] = cube[0][1][0];
		tmp[2] = cube[0][2][0];
		if (dir == '+') {
			for (int i = 0; i < 3; i++) cube[0][i][0] = cube[3][2 - i][2];
			for (int i = 0; i < 3; i++) cube[3][i][2] = cube[1][i][2];
			for (int i = 0; i < 3; i++) cube[1][i][2] = cube[2][2 - i][0];
			for (int i = 0; i < 3; i++) cube[2][i][0] = tmp[i];
		}
		else {
			for (int i = 0; i < 3; i++) cube[0][i][0] = cube[2][i][0];
			for (int i = 0; i < 3; i++) cube[2][i][0] = cube[1][2 - i][2];
			for (int i = 0; i < 3; i++) cube[1][i][2] = cube[3][i][2];
			for (int i = 0; i < 3; i++) cube[3][i][2] = tmp[2 - i];
		}
		break;
	case 'R':
		tmp[0] = cube[0][0][2];
		tmp[1] = cube[0][1][2];
		tmp[2] = cube[0][2][2];
		if (dir == '+') {
			for (int i = 0; i < 3; i++) cube[0][i][2] = cube[2][i][2];
			for (int i = 0; i < 3; i++) cube[2][i][2] = cube[1][2 - i][0];
			for (int i = 0; i < 3; i++) cube[1][i][0] = cube[3][i][0];
			for (int i = 0; i < 3; i++) cube[3][i][0] = tmp[2 - i];
		}
		else {
			for (int i = 0; i < 3; i++) cube[0][i][2] = cube[3][2 - i][0];
			for (int i = 0; i < 3; i++) cube[3][i][0] = cube[1][i][0];
			for (int i = 0; i < 3; i++) cube[1][i][0] = cube[2][2 - i][2];
			for (int i = 0; i < 3; i++) cube[2][i][2] = tmp[i];
		}
		break;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T, N;
	char plane, dir;

	cin >> T;

	for (int k = 0; k < T; k++) {
		cin >> N;
		initCube();

		for (int i = 0; i < N; i++) {
			cin >> plane >> dir;
			turnThisPlane(plane, dir);
			turnCube(plane, dir);
		}
		printCubeTop();
	}

	return 0;
}