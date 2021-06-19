#include <string>
#include <vector>

using namespace std;

int N, cnt;
vector<vector<int>> B;

vector<vector<vector<bool>>> type = {
    {{true, false, false}, {true, true, true}},
    {{false, false, true}, {true, true, true}},
    {{false, true, false}, {true, true, true}},
    {{false, true}, {false, true}, {true, true}},
    {{true, false}, {true, false}, {true, true}}
};

bool isRemovable(int t, int y, int x, int c){
    for(int i=x; i<x+c; i++){
        if(type[t][0][i-x] == true) continue;
        for(int j=0; j<y; j++){
            if(B[j][i] != 0) return false;
        }
    }
    return true;
}

void typeCheck(int y, int x, int r, int c){
    int blockNum;
    bool flag;

    for(int k=0; k<type.size(); k++){
        if(r==2 && k>2) continue;
        if(r==3 && k<3) continue;

        flag = true;
        blockNum = -1;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if (type[k][i][j] == false){
                    if(B[y+i][x+j] != 0){
                        flag = false;
                        break;
                    }
                }
                else{
                    if(B[y+i][x+j] == 0){
                        flag = false;
                        break;
                    }
                    if(blockNum == -1)
                        blockNum = B[y+i][x+j];
                    else if(blockNum != B[y+i][x+j]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag == false) break;
        }

        if(flag == true && isRemovable(k, y, x, c)){
            for(int i=0; i<r; i++)
                for(int j=0; j<c; j++)
                    B[y+i][x+j] = 0;
            cnt++;
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;

    N = board.size();
    B = board;

    do{
        cnt = 0;
        for(int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if(i+1 < N && j+2 < N)
                    typeCheck(i, j, 2, 3);
                if(i+2 < N && j+1 < N)
                    typeCheck(i, j, 3, 2);
            }
        }
        answer += cnt;
    } while(cnt != 0);

    return answer;
}