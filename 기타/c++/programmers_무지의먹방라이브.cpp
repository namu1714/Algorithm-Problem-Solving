#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int foodNum = food_times.size();
    vector<int> food_sorted;

    food_sorted.resize(food_times.size());
    copy(food_times.begin(), food_times.end(), food_sorted.begin());
    sort(food_sorted.begin(), food_sorted.end());

    long long cur = 0, prev = 0;
    int remained = -1, lastAmount = 0;
    for (int i = 0; i < foodNum; i++) {
        cur += (long long)(food_sorted[i] - lastAmount) * (foodNum - i);
        if (cur > k) {
            remained = (k - prev) % (foodNum - i);
            break;
        }
        lastAmount = food_sorted[i];
        prev = cur;
    }

    int cnt = 0;
    if (remained == -1)
        answer = -1;
    else {
        for (int i = 0; i < food_times.size(); i++) {
            if (food_times[i] <= lastAmount)
                continue;
            if (cnt == remained) {
                answer = i + 1;
                break;
            }
            cnt++;
        }
    }
    return answer;
}