#include <string>
#include <vector>

#define MAX_FRIEND 10

using namespace std;

int minFriend = MAX_FRIEND;

void check(int n, int distN, int remained, vector<int>& dist, vector<int>& weak, vector<bool>& wall) {
    if (remained == 0) {
        if (minFriend > dist.size() - distN - 1)
            minFriend = dist.size() - distN - 1;
        return;
    }
    if (distN < 0) return;

    for (int i = 0; i < weak.size(); i++) {
        if (wall[weak[i]] == false) continue;

        int cover = 0;
        vector<bool> wallCopy(wall);

        for (int j = weak[i]; j <= weak[i] + dist[distN]; j++) {
            if (wall[j % n] == true) {
                cover++;
                wallCopy[j % n] = false;
            }
        }

        check(n, distN - 1, remained - cover, dist, weak, wallCopy);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;

    vector<bool> initWall(n);

    for (int i = 0; i < weak.size(); i++) {
        initWall[weak[i]] = true;
    }

    check(n, dist.size() - 1, weak.size(), dist, weak, initWall);

    if (minFriend == MAX_FRIEND)
        answer = -1;
    else
        answer = minFriend;

    return answer;
}