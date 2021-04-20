#include <string>
#include <vector>

#define MAX_NUM 290000

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    int dp[MAX_NUM + 1];
    string tmp = "";

    fill(dp, dp + MAX_NUM + 1, 10);
    for(int i=1; i<10; i++){
        tmp += to_string(N);
        if(stoi(tmp) > MAX_NUM) break;
        dp[stoi(tmp)] = i;
    }

    dp[1] = 2;
    
    for(int i=1; i<=number * N; i++){
        if(dp[i] > 8) continue;
        for(int j=1; j<=i; j++){
            if(dp[i] + dp[j] > 8) continue;
            
            if(i + j <= number * N) 
                dp[i+j] = min(dp[i] + dp[j], dp[i+j]);
            if(i - j > 0) 
                dp[i-j] = min(dp[i] + dp[j], dp[i-j]);            
            if(i * j <= number * N) 
                dp[i*j] = min(dp[i] + dp[j], dp[i*j]);
            dp[i/j] = min(dp[i] + dp[j], dp[i/j]);
        }
    }
    
    if(dp[number] <= 8)
        answer = dp[number];
    else
        answer = -1;
    
    return answer;
}