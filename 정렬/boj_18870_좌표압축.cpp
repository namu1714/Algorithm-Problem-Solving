#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortList;

int search(int n) {
	int start = 0, end = sortList.size() - 1, mid;

	while (start <= end) {
		mid = (start + end) / 2;

		if (sortList[mid] == n) {
			return mid;
		}
		else if (sortList[mid] < n) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, tmp;
	vector<int> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sortList.resize(v.size());
	copy(v.begin(), v.end(), sortList.begin());

	sort(sortList.begin(), sortList.end());
	sortList.erase(unique(sortList.begin(), sortList.end()), sortList.end());

	for (int i : v)
		cout << search(i) << " ";

	return 0;
}