#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int answer;
	string s;
	vector<int> v;

	cin >> s;

	int startPos = 0, sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+') {
			sum += stoi(s.substr(startPos, i - startPos));
			startPos = i + 1;
		}
		else if (s[i] == '-') {
			sum += stoi(s.substr(startPos, i - startPos));
			v.push_back(sum);
			sum = 0;
			startPos = i + 1;
		}
	}
	sum += stoi(s.substr(startPos));
	v.push_back(sum);

	answer = v[0];
	for (int i = 1; i < v.size(); i++)
		answer -= v[i];

	cout << answer;

	return 0;
}