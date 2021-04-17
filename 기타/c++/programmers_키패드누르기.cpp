#include <string>
#include <vector>
#include <math.h>

using namespace std;

int keypad[12][2] = {{3, 1}, //0
                     {0, 0}, {0, 1}, {0, 2}, //1,2,3 
                     {1, 0}, {1, 1}, {1, 2}, //4,5,6
                     {2, 0}, {2, 1}, {2, 2}, //7,8,9
                     {3, 0}, {3, 2}}; //*,#

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lPos = 10, rPos = 11;
    int leftLen, rightLen;

    for(int i=0; i<numbers.size(); i++){
        switch(numbers[i])
        {
        case 1:
        case 4:
        case 7:
            answer += "L";
            lPos = numbers[i];
            break;
        case 3:
        case 6:
        case 9:
            answer += "R";
            rPos = numbers[i];
            break;
        case 2:
        case 5:
        case 8:
        case 0:
            leftLen = abs(keypad[lPos][0] - keypad[numbers[i]][0])
                    + abs(keypad[lPos][1] - keypad[numbers[i]][1]);
            rightLen = abs(keypad[rPos][0] - keypad[numbers[i]][0])
                     + abs(keypad[rPos][1] - keypad[numbers[i]][1]);

            if(leftLen == rightLen){
                if(hand.compare("left") == 0){
                    lPos = numbers[i];
                    answer += "L";
                } else {
                    rPos = numbers[i];
                    answer += "R";
                }
            }
            else if(leftLen < rightLen){
                lPos = numbers[i];
                answer += "L";
            }
            else {
                rPos = numbers[i];
                answer += "R";
            }
        }
    }
    return answer;
}