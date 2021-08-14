#include <string>
#include <vector>

using namespace std;

bool map[101][101][2]; //0은 기둥, 1은 보

bool buildPillar(int x, int y) {
    if (y == 0)
        return true;
    if (map[y - 1][x][0] == true)
        return true;
    if (map[y][x][1] == true || x - 1 >= 0 && map[y][x - 1][1] == true)
        return true;
    return false;
}

bool buildBeam(int x, int y) {
    if (map[y - 1][x][0] == true || map[y - 1][x + 1][0] == true)
        return true;
    if (x - 1 >= 0 && map[y][x - 1][1] == true
        && map[y][x + 1][1] == true)
        return true;
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (vector<int> frame : build_frame) {
        int x = frame[0];
        int y = frame[1];
        int type = frame[2];
        int cmd = frame[3];
        bool isOk;

        if (cmd == 1) {
            if (type == 0) {
                isOk = buildPillar(x, y);
            }
            else {
                isOk = buildBeam(x, y);
            }
            if (isOk == true) {
                map[y][x][type] = true;
            }
        }
        else {
            isOk = true;
            map[y][x][type] = false; //일단 제거
            if (type == 0) {
                if (y + 1 < n && map[y + 1][x][0] == true)
                    isOk = buildPillar(x, y + 1);
                if (isOk == true && x - 1 >= 0 && map[y + 1][x - 1][1] == true)
                    isOk = buildBeam(x - 1, y + 1);
                if (isOk == true && map[y + 1][x][1] == true)
                    isOk = buildBeam(x, y + 1);
            }
            else {
                if (map[y][x][0] == true)
                    isOk = buildPillar(x, y);
                if (isOk == true && map[y][x + 1][0] == true)
                    isOk = buildPillar(x + 1, y);
                if (isOk == true && x - 1 >= 0 && map[y][x - 1][1] == true)
                    isOk = buildBeam(x - 1, y);
                if (isOk == true && x + 1 < n && map[y][x + 1][1] == true)
                    isOk = buildBeam(x + 1, y);
            }
            if (isOk == false) {
                map[y][x][type] = true; //복원
            }
        }
    }

    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (map[y][x][0] == true)
                answer.push_back({ x, y, 0 });
            if (map[y][x][1] == true)
                answer.push_back({ x, y, 1 });
        }
    }

    return answer;
}