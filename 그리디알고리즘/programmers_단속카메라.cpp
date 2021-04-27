#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compare(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), compare);
    
    int car = 0;
    
    while(car < routes.size()){
        int start = routes[car][0];
        int end = routes[car][1];
        
        for(; car<routes.size(); car++){
            if(routes[car][0] <=end)
                end = min(end, routes[car][1]);
            else 
                break;
        }
        answer++;
    }
    return answer;
}