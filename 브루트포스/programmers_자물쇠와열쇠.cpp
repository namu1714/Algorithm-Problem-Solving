#include <string>
#include <vector>

using namespace std;

int N, M, K;

bool check(vector<vector<int>>& key, vector<vector<int>>& lock) {
    for (int i = M - 1; i < M - 1 + N; i++) {
        for (int j = M - 1; j < M - 1 + N; j++) {
            if (key[i][j] == 1 && lock[i][j] == 1
                || key[i][j] == 0 && lock[i][j] == 0)
                return false;
        }
    }
    return true;
}

void rotate(vector<vector<int>>& key) {
    vector<vector<int>> tmp(key);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            key[j][M - 1 - i] = tmp[i][j];
        }
    }
}

void keyCopy(int r, int c, vector<vector<int>>& key, vector<vector<int>>& keyMap) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            keyMap[i + r][j + c] = key[i][j];
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    N = lock.size();
    M = key.size();
    K = N + (M - 1) * 2;

    vector<vector<int>> lockMap(K, vector<int>(K, -1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            lockMap[M + i - 1][M + j - 1] = lock[i][j];
        }
    }

    int rotateCnt = 4;

    while (rotateCnt--) {
        for (int i = 0; i <= K - M; i++) {
            for (int j = 0; j <= K - M; j++) {
                vector<vector<int>> keyMap(K, vector<int>(K, 0));
                keyCopy(i, j, key, keyMap);
                if (check(keyMap, lockMap) == true) {
                    answer = true;
                    break;
                }
            }
            if (answer == true) break;
        }
        if (answer == true) break;

        rotate(key);
    }

    return answer;
}