#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.second < p2.second)
		return true;
	else if (p1.second == p2.second) {
		if (p1.first < p2.first)
			return true;
		else
			return false;
	}
	else
		return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("sample_input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n;
		cin >> n;
		vector<pair<int, int>> v;

		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;

			v.push_back(make_pair(a, b));
		}

		sort(v.begin(), v.end(), cmp);

		int ans = INT_MIN;
		int base = 0;
		for (int i = 0; i < v.size(); ++i) {
			base += v[i].first;
			if (base > v[i].second && ans < base - v[i].second)
				ans = base - v[i].second;
		}
		if (ans == INT_MIN)
			ans = 0;
		cout << "#" << t << " " << ans << "\n";
	}


	return 0;
}