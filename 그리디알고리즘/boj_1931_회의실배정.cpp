#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

bool compare(pair<ll, ll> a, pair<ll, ll> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	vector<pair<ll, ll>> session;
	int N, answer = 0;
	ll start, end, cur;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		session.push_back({ start,end });
	}
	sort(session.begin(), session.end(), compare);

	cur = 0;
	for (int i = 0; i < N; i++) {
		if (session[i].first >= cur) {
			cur = session[i].second;
			answer++;
		}
	}

	cout << answer;

	return 0;
}