#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int start = 0, end = *max_element(stones.begin(), stones.end());
    int mid;

    while(start < end){
        mid = (start + end) / 2;

        int zeros = 0, maxZeros = 0;
        for(int i=0; i<stones.size(); i++){
            if(stones[i] - mid <= 0){
                zeros++;
            }
            else{
                maxZeros = max(zeros, maxZeros);
                zeros = 0;
            }
            if(zeros > k) break;
        }
        maxZeros = max(zeros, maxZeros);

        if(maxZeros >= k)
            end = mid;
        else
            start = mid + 1;
    }
    answer = start;

    return answer;
}