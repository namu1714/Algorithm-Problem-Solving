#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool check[31][31];

void check4Block(int c, int r, vector<string> board){
    char ch = board[c][r];
    if(board[c][r+1] == ch && board[c+1][r] == ch && board[c+1][r+1] == ch){
        check[c][r] = true;
        check[c][r+1] = true;
        check[c+1][r] = true;
        check[c+1][r+1] = true;
    }
    return;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int flag;
    
    do{
        flag = false;
        memset(check, 0, sizeof(check));
        
        for(int i=0; i<m-1; i++){
            for(int j=0; j<n-1; j++){
                if(board[i][j] != ' ') check4Block(i, j, board);
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(check[i][j]) {
                    answer++;
                    board[i][j] = ' ';
                }
            }
        }
        
        for(int i=0; i<m-1; i++){
            for(int j=0; j<n; j++){
                
                if(board[i][j] != ' ' && board[i+1][j] == ' '){
                    for(int k=i; k>=0; k--)
                        board[k+1][j] = board[k][j];
                    board[0][j] = ' ';
                    flag = true;
                }
            }
        }
    } while(flag);
    
    return answer;
}