#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;

    int thisDoll;

    for(int i=0; i<moves.size(); i++){
        bool flag = false;

        for(int j=0; j<board.size(); j++){
            if(board[j][moves[i]-1] != 0){
                thisDoll =  board[j][moves[i]-1];
                board[j][moves[i]-1] = 0;
                flag = true;
                break;
            }
        }
        if(flag == true){
            if(!s.empty() && thisDoll == s.top()){
                s.pop();
                answer += 2;
            }
            else{
                s.push(thisDoll);
            }
        }
    }
    return answer;
}