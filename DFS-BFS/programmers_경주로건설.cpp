#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int costs[25][25] = {0, };

typedef struct pos{
    int direction;
    int x;
    int y;
    int cost;
};

void bfs(vector<vector<int>> &board, int N){
    queue<pos> Q;
    int minCost = 10000000;

    Q.push({0, 0, 0, 0});
    Q.push({1, 0, 0, 0});

    while(!Q.empty()){
        pos p = Q.front();
        Q.pop();

        if (costs[p.y][p.x] == 0 || costs[p.y][p.x] >= p.cost)
            costs[p.y][p.x] = p.cost;
        else
            continue;

        if(p.x == N - 1 && p.y == N - 1)
            continue;

        for(int i=0; i<4; i++){
            if(p.direction == 0 || p.direction || 1){ //반대방향
                if(i == p.direction + 2) continue;
            }
            else{
                if(i == p.direction - 2) continue;
            }

            int xx = p.x + dx[i];
            int yy = p.y + dy[i];

            if(xx >= 0 && xx < N && yy >= 0 && yy < N 
                && board[yy][xx] == 0){

                int costAdd = 100;
                if(i != p.direction)
                    costAdd += 500;

                Q.push({i, xx, yy, p.cost + costAdd});
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();

    bfs(board, N);
    answer = costs[N-1][N-1];

    return answer;
}