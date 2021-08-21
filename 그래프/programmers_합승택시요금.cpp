#include <string>
#include <vector>
#include <algorithm>

#define INF 100000000

using namespace std;

int dist[200][200];

void initDist(int n){
    fill(&dist[0][0], &dist[199][200], INF);
    for(int i=0; i<n; i++)
        dist[i][i] = 0;
}

void floyd(int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    initDist(n);
    
    for (vector<int> fare : fares){
        dist[fare[0] - 1][fare[1] - 1] = fare[2];
        dist[fare[1] - 1][fare[0] - 1] = fare[2];
    }
    
    floyd(n);
    
    s -= 1; a -= 1; b-= 1;
    
    for(int i=0; i<n; i++){
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    
    return answer;
}