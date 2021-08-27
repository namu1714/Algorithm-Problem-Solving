#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct Cursor {
    int x, y;
    int moves;
};

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };


int bfs(vector<vector<int>>& board, pair<int, int>& start, pair<int, int> dest) {
    queue<Cursor> Q;
    bool check[4][4] = { 0, };

    if (start == dest)
        return 0;

    Q.push({ start.second, start.first, 0 });
    check[start.first][start.second] = true;

    while (!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        int moves = Q.front().moves;
        Q.pop();

        for (int i = 0; i < 4 * 2; i++) {
            int xx = x;
            int yy = y;

            if (i >= 4) {
                while (true) {
                    if (xx + dx[i % 4] < 0 || xx + dx[i % 4] >= 4 ||
                        yy + dy[i % 4] < 0 || yy + dy[i % 4] >= 4)
                        break;

                    xx += dx[i % 4];
                    yy += dy[i % 4];
                    if (board[yy][xx] > 0) break;
                }
            }
            else {
                xx += dx[i];
                yy += dy[i];
                if (xx < 0 || xx >= 4 || yy < 0 || yy >= 4)
                    continue;
            }

            if (check[yy][xx] == true)
                continue;

            if (yy == dest.first && xx == dest.second) {
                start = dest;
                return moves + 1;
            }
            check[yy][xx] = true;
            Q.push({ xx, yy, moves + 1 });
        }
    }
    return -1;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    vector<int> cards;
    vector<vector<pair<int, int>>> position(6);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] > 0) {
                int index = board[i][j] - 1;
                cards.push_back(index);
                position[index].push_back({ i, j });
            }
        }
    }

    sort(cards.begin(), cards.end());
    cards.erase(unique(cards.begin(), cards.end()), cards.end());

    int minCnt = 1000000;
    do {
        for (int k = 0; k < (1 << cards.size()); k++) {
            bool flag = true;
            pair<int, int> cur = { r, c };
            vector<vector<int>> boardCopy(board);
            int add, cnt = 0;

            for (int i = 0; i < cards.size(); i++) {
                int card = cards[i];
                if (((1 << i) & k) == 0) {
                    add = bfs(boardCopy, cur, position[card][0]);
                    if (add < 0) {
                        flag = false;
                        break;
                    }
                    cnt += add;

                    add = bfs(boardCopy, cur, position[card][1]);
                    if (add < 0) {
                        flag = false;
                        break;
                    }
                    cnt += add;
                }
                else {
                    add = bfs(boardCopy, cur, position[card][1]);
                    if (add < 0) {
                        flag = false;
                        break;
                    }
                    cnt += add;
                    add = bfs(boardCopy, cur, position[card][0]);
                    if (add < 0) {
                        flag = false;
                        break;
                    }
                    cnt += add;
                }
                boardCopy[position[card][0].first][position[card][0].second] = 0;
                boardCopy[position[card][1].first][position[card][1].second] = 0;
                cnt += 2; //enter
            }

            if (flag == true)
                minCnt = min(minCnt, cnt);
        }
    } while (next_permutation(cards.begin(), cards.end()));

    answer = minCnt;

    return answer;
}