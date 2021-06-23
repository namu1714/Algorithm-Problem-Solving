#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	multiset<int> m;
	int T, k, num;
	char cmd;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> k;
		m.clear();

		for (int j = 0; j < k; j++) {
			cin >> cmd >> num;

			if (cmd == 'I') {
				m.insert(num);
			}
			else if (cmd == 'D') {
				if (m.empty()) continue;

				if (num == 1)
					m.erase(--m.end());
				else
					m.erase(m.begin());
			}
		}
		if (m.empty())
			cout << "EMPTY" << "\n";
		else
			cout << *(--m.end()) << " " << *m.begin() << "\n";
	}

	return 0;
}