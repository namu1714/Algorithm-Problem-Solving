#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	vector<pair<int, int>> house;
	vector<pair<int, int>> chicken;
	vector<int> chickenDist[100];
	int N, M;
	int minCityDist = 10000;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1)
				house.push_back({ i,j });
			else if (tmp == 2)
				chicken.push_back({ i,j });
		}
	}

	for (int i = 0; i < house.size(); i++) {
		for (int j = 0; j < chicken.size(); j++) {
			chickenDist[i].push_back(abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
		}
	}

	vector<int> comb;
	for (int i = 0; i < chicken.size() - M; i++)
		comb.push_back(0);
	for (int i = 0; i < M; i++)
		comb.push_back(1);

	do {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int minDist = 1000;
			for (int j = 0; j < chicken.size(); j++) {
				if (comb[j] == 0)continue;
				minDist = min(minDist, chickenDist[i][j]);
			}
			sum += minDist;
		}
		minCityDist = min(minCityDist, sum);
	} while (next_permutation(comb.begin(), comb.end()));

	cout << minCityDist;

	return 0;
}