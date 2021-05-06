#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long getPeopleNum(long long n, vector<int> times){
    long long sum = 0;
    for(int i=0; i<times.size(); i++){
        sum += n/times[i];
    }
    return sum;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long start, end, mid;
    
    sort(times.begin(), times.end());
    long long tmp = n / times.size();
    start = tmp * times[0];
    end =  (tmp + 1) * times[times.size() - 1];
    
    while(start < end){
        mid = (start + end) / 2;
        long long people = getPeopleNum(mid, times);
        
        if (people > n)
            end = mid;
        else if (people < n)
            start = mid + 1;
        else
            end = mid;
    }
    
    answer = start;
    return answer;
}