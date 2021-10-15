#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, D;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int calDistance(int r1, int c1, int r2, int c2) {
	return abs(r1 - r2) + abs(c1 - c2);
}

void moveEnemy(vector<pair<int, int>>& enemy, vector<bool>& isEnemyAlive) {
	for (int i = 0; i < enemy.size(); i++) {
		if (isEnemyAlive[i] == false)
			continue;
		if (enemy[i].first < N - 1) {
			enemy[i].first++;
		}
		else {
			isEnemyAlive[i] = false;
		}
	}
}

bool isExistEnemy(vector<bool>& isEnemyAlive) {
	for (int i = 0; i < isEnemyAlive.size(); i++) {
		if (isEnemyAlive[i] == true)
			return true;
	}
	return false;
}

int killEnemy(vector<int>& target, vector<bool>& isEnemyAlive) {
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (target[i] == -1) continue;
		if (isEnemyAlive[target[i]] == true) {
			isEnemyAlive[target[i]] = false;
			cnt++;
		}
	}
	return cnt;
}

int getTarget(int col, vector<pair<int, int>>& enemy, vector<bool>& isEnemyAlive) {
	int target = -1;
	int minDist = D + 1;
	for (int i = 0; i < enemy.size(); i++) {
		if (isEnemyAlive[i] == false) continue;

		int dist = calDistance(enemy[i].first, enemy[i].second, N, col);
		if (dist < minDist) {
			minDist = dist;
			target = i;
		}
	}
	return target;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<pair<int, int>> enemy;
	vector<bool> isEnemyAlive;

	cin >> N >> M >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1) {
				enemy.push_back({ i,j });
				isEnemyAlive.push_back(true);
			}
		}
	}
	sort(enemy.begin(), enemy.end(), compare);

	vector<int> archer;
	for (int i = 0; i < M - 3; i++)
		archer.push_back(0);
	for (int i = 0; i < 3; i++)
		archer.push_back(1);

	int answer = 0;

	do {
		vector<pair<int, int>> enemyCopy(enemy);
		for (int i = 0; i < isEnemyAlive.size(); i++)
			isEnemyAlive[i] = true;

		int deadEnemy = 0;

		while (isExistEnemy(isEnemyAlive) == true) {
			vector<int> target;

			for (int i = 0; i < M; i++) {
				if (archer[i] == 0) continue;
				target.push_back(getTarget(i, enemyCopy, isEnemyAlive));
			}

			deadEnemy += killEnemy(target, isEnemyAlive);
			moveEnemy(enemyCopy, isEnemyAlive);
		}

		answer = max(answer, deadEnemy);

	} while (next_permutation(archer.begin(), archer.end()));

	cout << answer;

	return 0;
}