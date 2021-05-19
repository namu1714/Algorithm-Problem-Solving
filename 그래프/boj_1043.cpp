#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[50];
bool check[50] = { 0, };

void dfs(int n) {
	check[n] = true;
	for (int i : graph[n]) {
		if (!check[i]) dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, num, tmp;
	int lieParty;
	vector<int> party[50];
	vector<int> truth;

	cin >> N >> M;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> tmp;
		truth.push_back(tmp - 1);
	}

	for (int i = 0; i < M; i++) {
		int point;
		cin >> num;

		for (int j = 0; j < num; j++) {
			cin >> tmp;

			if (j == 0) { //첫 참가자에 다른 참가자들 연결 
				point = tmp - 1;
			}
			else {
				graph[point].push_back(tmp - 1);
				graph[tmp - 1].push_back(point);
			}

			party[i].push_back(tmp - 1);
		}
	}

	for (int i : truth) {
		if (!check[i]) dfs(i);
	}

	// 진실을 아는 사람이 없는 파티 체크
	lieParty = 0;
	for (int i = 0; i < M; i++) {
		bool flag = false;
		for (int p : party[i]) {
			if (check[p] == true) {
				flag = true;
				break;
			}
		}
		if (!flag) lieParty++;
	}

	printf("%d", lieParty);

	return 0;
}