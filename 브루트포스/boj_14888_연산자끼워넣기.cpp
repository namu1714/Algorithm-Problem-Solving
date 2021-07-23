#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N;
	int A[11];
	vector<char> operand;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int tmp;
	char ops[4] = { '+', '-', '*', '/' };
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		for (int k = 0; k < tmp; k++)
			operand.push_back(ops[i]);
	}

	sort(operand.begin(), operand.end());

	int maxNum = -100000000, minNum = 100000000;
	do {
		int result = A[0];
		for (int i = 0; i < operand.size(); i++) {
			switch (operand[i]) {
			case '+':
				result += A[i + 1];
				break;
			case '-':
				result -= A[i + 1];
				break;
			case '*':
				result *= A[i + 1];
				break;
			case '/':
				result /= A[i + 1];
				break;
			}
		}
		maxNum = max(maxNum, result);
		minNum = min(minNum, result);

	} while (next_permutation(operand.begin(), operand.end()));

	cout << maxNum << "\n";
	cout << minNum << "\n";

	return 0;
}