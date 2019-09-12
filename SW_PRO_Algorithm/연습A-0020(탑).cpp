#include <iostream>
#include <vector>
using namespace std;

int A_0020() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n;
		cin >> n;
		vector<int> heights(n);
		for (int i = 0; i < n; ++i)
			cin >> heights[i];

		int j = 0;
		long long ans = 0;

		for (int i = n - 1; i >= 1; --i) {
			int temp = heights[i];
			for (j = i - 1; j >= 0; --j) {
				if (temp < heights[j]) {
					ans += j + 1;
					ans %= 1000000007;
					break;
				}
			}
		}
		cout << "#" << t << " " << ans << "\n";
	}
	
	return 0;
}