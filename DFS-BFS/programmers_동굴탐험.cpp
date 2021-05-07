#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> room[200000];
vector<int> roomWay[200000];
bool visit[200000] = {0, }, finished[200000] = {0, };

void bfs(){
    queue<int> Q;
    Q.push(0);
    
    while(!Q.empty()){
        int num = Q.front();
        Q.pop();
        visit[num] = true;
        
        for(int next : room[num]){
            if (visit[next]) continue;
            Q.push(next);
            roomWay[num].push_back(next);
        }
    }
}

bool isNotCycle(int num){
    visit[num] = true;
    
    for(int next : roomWay[num]){
        if(visit[next] == true){
            if(finished[next] == false)
                return false;
        }
        else{
            if(isNotCycle(next) == false)
               return false;
        }
    }
    finished[num] = true;
    return true;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    
    for(int i=0; i<path.size(); i++){
        room[path[i][0]].push_back(path[i][1]);
        room[path[i][1]].push_back(path[i][0]);
    }

    bfs();

    for(int i=0; i<order.size(); i++){
        roomWay[order[i][0]].push_back(order[i][1]);
    }
    
    fill_n(visit, n, false);
    answer = isNotCycle(0);
    
    return answer;
}