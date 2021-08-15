#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct Position {
    int x, y;
    int dir; //가로, 세로
    int cnt;
};

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

bool visited[100][100][2] = { 0, };

bool rangeCheck(int N, int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N)
        return false;
    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;

    queue<Position> Q;
    int N = board.size();

    Q.push({ 0, 0, 0, 0 });
    visited[0][0][0] = true;

    while (!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        int dir = Q.front().dir;
        int cnt = Q.front().cnt;

        Q.pop();

        if (x == N - 1 && y == N - 1 || x + dx[dir] == N - 1 && y + dy[dir] == N - 1) {
            answer = cnt;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            int nxx = xx + dx[dir];
            int nyy = yy + dy[dir];

            if (rangeCheck(N, xx, yy) == false)   continue;
            if (rangeCheck(N, nxx, nyy) == false) continue;

            if (board[yy][xx] == 1 || board[nyy][nxx] == 1)
                continue;

            if (visited[yy][xx][dir] == false) {
                visited[yy][xx][dir] = true;
                Q.push({ xx, yy, dir, cnt + 1 });
            }
        }

        if (dir == 0) {
            if (rangeCheck(N, x + 1, y + 1) == true
                && board[y + 1][x] == 0 && board[y + 1][x + 1] == 0) {
                if (visited[y][x][1] == false) {
                    visited[y][x][1] == true;
                    Q.push({ x, y, 1, cnt + 1 });
                }
                if (visited[y][x + 1][1] == false) {
                    visited[y][x + 1][1] == true;
                    Q.push({ x + 1, y, 1, cnt + 1 });
                }
            }
            if (rangeCheck(N, x + 1, y - 1) == true
                && board[y - 1][x] == 0 && board[y - 1][x + 1] == 0) {
                if (visited[y - 1][x][1] == false) {
                    visited[y - 1][x][1] == true;
                    Q.push({ x, y - 1, 1, cnt + 1 });
                }
                if (visited[y - 1][x + 1][1] == false) {
                    visited[y - 1][x + 1][1] == true;
                    Q.push({ x + 1, y - 1, 1, cnt + 1 });
                }
            }
        }
        else {
            if (rangeCheck(N, x + 1, y + 1) == true
                && board[y][x + 1] == 0 && board[y + 1][x + 1] == 0) {
                if (visited[y][x][0] == false) {
                    visited[y][x][0] == true;
                    Q.push({ x, y, 0, cnt + 1 });
                }
                if (visited[y + 1][x][0] == false) {
                    visited[y + 1][x][0] == true;
                    Q.push({ x, y + 1, 0, cnt + 1 });
                }
            }
            if (rangeCheck(N, x - 1, y + 1) == true
                && board[y][x - 1] == 0 && board[y + 1][x - 1] == 0) {
                if (visited[y][x - 1][0] == false) {
                    visited[y][x - 1][0] == true;
                    Q.push({ x - 1, y, 0, cnt + 1 });
                }
                if (visited[y + 1][x - 1][0] == false) {
                    visited[y + 1][x - 1][0] == true;
                    Q.push({ x - 1, y + 1, 0, cnt + 1 });
                }
            }
        }
    }

    return answer;
}