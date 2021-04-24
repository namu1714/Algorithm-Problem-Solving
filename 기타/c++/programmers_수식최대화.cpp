#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void getExpArr(string expr, vector<long long> &num, vector<char> &op) {
    num.clear();
    op.clear();
    string tmp = "";

    for(int i=0; i<expr.size(); i++){
        if(!isdigit(expr[i])){
            op.push_back(expr[i]);
            num.push_back(stoi(tmp));
            tmp = "";
        }
        else{
            tmp += expr[i]; 
        }
    }
    num.push_back(stoi(tmp));
}

long long calculate(long long a, long long b, char op){ 
    switch(op){
        case '*':
            return a * b;
        case '+':
            return a + b;
        case '-':
            return a - b;
    }
    return -1;
}

long long solution(string expression) {
    long long answer = 0;
    char priority[3] = {'*', '+', '-'};

    vector<long long> num;
    vector<char> op;

    do{
        getExpArr(expression, num, op);

        for(int i=0; i<3; i++){
            for(int j=0; j<op.size(); j++){
                if(op[j] == priority[i]){
                    long long result = calculate(num[j], num[j+1], op[j]);

                    op.erase(op.begin() + j);
                    num.erase(num.begin() + j);
                    num.erase(num.begin() + j);
                    num.insert(num.begin() + j, result);

                    j--;
                }
            }
        }
        if(abs(num[0]) > answer)
            answer = abs(num[0]);

    } while(next_permutation(priority, priority + 3));

    return answer;
}