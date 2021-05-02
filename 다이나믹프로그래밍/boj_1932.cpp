#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, tmp, maxSum;
	vector<int> tri[500];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &tmp);
			tri[i].push_back(tmp);
		}
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) { 
				tri[i][j] += tri[i - 1][j]; 
			} else if (j == i) { 
				tri[i][j] += tri[i - 1][j - 1]; 
			} else {
				tri[i][j] += max(tri[i - 1][j], tri[i - 1][j - 1]);
			}
		}
	}

	maxSum = 0;
	for (int i = 0; i < n; i++)
		maxSum = max(maxSum, tri[n - 1][i]);

	printf("%d", maxSum);

	return 0;
}