#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int start = 1, end = distance, mid;
    int cnt, prev;
    
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    
    while(start <= end){
        mid = (start + end) / 2;
        prev = 0; cnt = 0;
        
        for(int i=0; i<rocks.size(); i++){
            if(rocks[i] - prev < mid)
                cnt++;
            else
                prev = rocks[i];
        }
        
        if(cnt <= n)
            start = mid + 1;
        else
            end = mid - 1;
    }
    
    answer = end;
    return answer;
}