#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define YES "yes"
#define NO "danger"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int x, n;
		cin >> x >> n;

		x *= 10000000;			// 나노미터로 단위환산
		vector<int> v;
		for (int i = 0; i < n; ++i) {
			int d;
			cin >> d;
			v.push_back(d);
		}
		sort(v.begin(), v.end());

		int lo = 0, hi = n - 1;
		bool flag = false;
		while (lo < hi) {
			int sum = v[lo] + v[hi];
			if (sum < x)
				++lo;
			else if (sum > x)
				--hi;
			else {
				cout << "#" << t << " " << YES << " " << v[lo] << " " << v[hi] << "\n";
				flag = true;
				break;
			}
		}
		if (!flag) 
			cout << "#" << t << " " << NO << "\n";
	}
	return 0;
}