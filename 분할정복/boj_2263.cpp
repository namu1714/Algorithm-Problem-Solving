#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inorder;
vector<int> postorder;

void traverse(int iStart, int iEnd, int pStart, int pEnd) {
	int root = postorder[pEnd];
	printf("%d ", root);

	if (iStart == iEnd) return;

	int rootIndex = find(inorder.begin() + iStart, inorder.begin() + iEnd + 1, root) - inorder.begin();
	int leftNum = rootIndex - iStart;

	if (rootIndex != iStart) traverse(iStart, rootIndex - 1, pStart, pStart + leftNum - 1);
	if (rootIndex != iEnd)	traverse(rootIndex + 1, iEnd, pStart + leftNum, pEnd - 1);
}

int main() {
	int n, tmp;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		inorder.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		postorder.push_back(tmp);
	}

	traverse(0, n - 1, 0, n - 1);

	return 0;
}