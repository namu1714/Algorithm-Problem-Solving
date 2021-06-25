#include <string>
#include <cstring>
#include <vector>
#include <limits.h>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<pair<int, int>> island[100];
    bool checked[100];
    int minCost, tmp;

    memset(checked, false, sizeof(checked));

    for (int i = 0; i < costs.size(); i++) {
        island[costs[i][0]].push_back(make_pair(costs[i][1], costs[i][2]));
        island[costs[i][1]].push_back(make_pair(costs[i][0], costs[i][2]));
    }

    vector<pair<int, int>>::iterator it;

    checked[0] = true;
    for (int i = 1; i < n; i++) {
        minCost = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!checked[j]) continue;
            for (it = island[j].begin(); it != island[j].end(); ++it) {
                if (!checked[it->first] && it->second < minCost) {
                    tmp = it->first;
                    minCost = it->second;
                }
            }
        }
        checked[tmp] = true;
        answer += minCost;
    }

    return answer;
}