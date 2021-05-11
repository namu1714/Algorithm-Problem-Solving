#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2;
	int dp[1000] = { 0, };
	int maxSeq;

	cin >> s1 >> s2;
	
	for (int i = 0; i < s2.length(); i++) {
		maxSeq = 0;
		for (int j = 0; j < s1.length(); j++) {
			int tmp = dp[j];
			if (s1[j] == s2[i])
				dp[j] = maxSeq + 1;
			if (tmp > maxSeq) 
				maxSeq = tmp;
		}
	}

	maxSeq = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (dp[i] > maxSeq) maxSeq = dp[i];
	}
	cout << maxSeq;

	return 0;
}