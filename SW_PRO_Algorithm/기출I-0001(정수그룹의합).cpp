#include <iostream>
#include <string.h>
#include <climits>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		vector<int> v(6);
		vector<int> check(6, 1);
		for (int i = 0; i < 6; ++i)
			cin >> v[i];

		int ans_diff = INT_MAX;
		int ans1 = 0;
		int ans2 = 0;
		check[0] = check[1] = check[2] = 0;

		do {
			int sum1 = 0;
			int sum2 = 0;

			for (int i = 0; i < 6; ++i) {
				if (check[i] == 1)
					sum1 += v[i];
				else
					sum2 += v[i];
			}

			if (ans_diff > abs(sum1 - sum2)) {
				ans_diff = abs(sum1 - sum2);
				ans1 = sum1;
				ans2 = sum2;
			}
		} while (next_permutation(check.begin(), check.end()));

		if (ans1 < ans2)
			cout << "#" << t << " " << ans1 << " " << ans2 << "\n";
		else
			cout << "#" << t << " " << ans2 << " " << ans1 << "\n";
	}

	return 0;
}