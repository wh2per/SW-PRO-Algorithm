#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, m;
		cin >> n >> m;

		vector<int> v;
		vector<int> temp;
		int prev = 0;

		for (int i = 0; i < n; ++i) {
			int a, b, c;
			cin >> a >> b >> c;

			int sum = a * 60 * 1000 + b * 1000 + c;		// 밀리초로 환산
			v.push_back(sum - prev);
			temp.push_back(sum);
			if (i % m == m - 1) {
				sort(temp.begin(), temp.end());
				prev = temp[m - 1];
				temp.clear();
			}
		}

		sort(v.begin(), v.end());
		cout << "#" << t << " " << v[0] / 1000 << " " << v[0] % 1000 << "\n";
	}


	return 0;
}

