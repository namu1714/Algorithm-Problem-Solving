#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct StageInfo {
    int num;
    int notClear;
    int reach;
};

bool compare(StageInfo a, StageInfo b) {
    float failureA = 0;
    float failureB = 0;

    if (a.reach > 0)
        failureA = (float)a.notClear / a.reach;
    if (b.reach > 0)
        failureB = (float)b.notClear / b.reach;

    if (failureA == failureB)
        return a.num < b.num;

    return failureA > failureB;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<StageInfo> v;

    for (int i = 0; i < N; i++)
        v.push_back({ i + 1, 0, 0 });

    for (int i : stages) {
        if (i > N)
            v[N - 1].reach++;
        else
            v[i - 1].notClear++;
    }

    int sum = v[N - 1].reach;

    for (int i = N - 1; i >= 0; i--) {
        sum += v[i].notClear;
        v[i].reach = sum;
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++)
        answer.push_back(v[i].num);

    return answer;
}