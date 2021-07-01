#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(vector<string> arr)
{
    int answer = -1;
    int dp[2][101][101];
    vector<int> nums;
    vector<char> ops;

    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0)
            nums.push_back(stoi(arr[i]));
        else
            ops.push_back(arr[i][0]);
    }

    for (int i = 0; i < nums.size(); i++) {
        dp[0][i][i] = nums[i];
        dp[1][i][i] = nums[i];
    }

    for (int k = 1; k < nums.size(); k++) {
        for (int i = 0; i + k < nums.size(); i++) {
            dp[0][i][i + k] = 1000000;
            dp[1][i][i + k] = -1000000;

            for (int j = i; j < i + k; j++) {
                if (ops[j] == '+') {
                    dp[0][i][i + k] = min(dp[0][i][i + k], dp[0][i][j] + dp[0][j + 1][i + k]);
                    dp[1][i][i + k] = max(dp[1][i][i + k], dp[1][i][j] + dp[1][j + 1][i + k]);
                }
                else {
                    dp[0][i][i + k] = min(dp[0][i][i + k], dp[0][i][j] - dp[1][j + 1][i + k]);
                    dp[1][i][i + k] = max(dp[1][i][i + k], dp[1][i][j] - dp[0][j + 1][i + k]);
                }
            }
        }
    }
    answer = dp[1][0][nums.size() - 1];

    return answer;
}