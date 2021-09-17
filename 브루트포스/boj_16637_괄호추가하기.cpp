#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

bool checkIsValid(int n, int op_cnt) {
	for (int i = 0; i < op_cnt - 1; i++) {
		if ((1 << i & n) > 0 && (1 << (i + 1) & n) > 0) {
			return false;
		}
	}
	return true;
}

int calculate(int a, int b, char op) {
	int ret = -1;

	switch (op) {
	case '+':
		ret = a + b;
		break;
	case '-':
		ret = a - b;
		break;
	case '*':
		ret = a * b;
		break;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, op_cnt;
	vector<char> op;
	vector<int> num;

	cin >> N;

	string tmp;
	cin >> tmp;

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0)
			num.push_back(tmp[i] - '0');
		else
			op.push_back(tmp[i]);
	}
	op_cnt = op.size();

	int answer = INT_MIN;
	vector<char> new_op;
	vector<int> new_num;

	for (int k = 0; k < (1 << op_cnt); k++) {
		if (op_cnt == 0) {
			answer = num[k];
			break;
		}

		if (checkIsValid(k, op_cnt) == false)
			continue;

		new_op.clear();
		new_num.clear();
		new_num.push_back(num[0]);

		for (int i = 0; i < op_cnt; i++) {
			if ((1 << i & k) > 0) {
				int tmp = calculate(new_num.back(), num[i + 1], op[i]);
				new_num.pop_back();
				new_num.push_back(tmp);
			}
			else {
				new_num.push_back(num[i + 1]);
				new_op.push_back(op[i]);
			}
		}

		int sum = new_num[0];
		for (int i = 0; i < new_op.size(); i++) {
			sum = calculate(sum, new_num[i + 1], new_op[i]);
		}

		answer = max(sum, answer);
	}

	cout << answer;

	return 0;
}