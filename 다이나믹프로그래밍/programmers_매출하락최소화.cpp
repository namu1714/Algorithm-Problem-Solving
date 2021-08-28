#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree[300001];
int dp[300001][2] = { 0, }; //0은 미포함, 1은 포함

void find(vector<int>& sales, int root) {
    for (int child : tree[root]) {
        find(sales, child);
    }

    dp[root][1] = sales[root - 1];

    if (tree[root].size() == 0) return;

    for (int child : tree[root]) {
        dp[root][1] += min(dp[child][0], dp[child][1]);
    }

    bool flag = false;
    for (int child : tree[root]) {
        dp[root][0] += min(dp[child][0], dp[child][1]);
        if (dp[child][0] >= dp[child][1])
            flag = true;
    }
    if (flag == false) {
        int minDiff = 100000000;
        for (int child : tree[root]) {
            minDiff = min(minDiff, dp[child][1] - dp[child][0]);
        }
        dp[root][0] += minDiff;
    }
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    for (vector<int> link : links) {
        tree[link[0]].push_back(link[1]);
    }

    find(sales, 1);

    answer = min(dp[1][0], dp[1][1]);

    return answer;
}