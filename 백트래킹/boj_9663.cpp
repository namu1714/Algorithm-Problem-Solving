#include <stdio.h>
#include <math.h>

int N, cnt = 0;
int queen[15];

void backtracking(int n){
	if(n == N){
        cnt++;
        return;
    }
    for(int i=0; i<N; i++){
        bool flag = true;
        for(int j=0; j<n; j++){
            if(queen[j] == i) {
                flag = false;
                break;
            }
            if(n - j == abs(queen[j] - i)) {
                flag = false;
                break;
            }
        }
        if (!flag) continue;
        queen[n] = i;
        backtracking(n + 1);
    }
}

int main() {
	scanf("%d", &N);
    backtracking(0);
    printf("%d", cnt);
    return 0;
}