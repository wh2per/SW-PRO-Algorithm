#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int A_0023() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, k;
		cin >> n >> k;
		vector<int> v1;
		vector<int> v2;

		for (int i = 0; i < n / 2; ++i) {
			int num;
			cin >> num;
			v1.push_back(num);
		}

		for (int i = n / 2; i < n; ++i) {
			int num;
			cin >> num;
			v2.push_back(num);
		}

		int count = 0;

		int size1 = v1.size();
		int size2 = v2.size();

		unordered_map<int, int> m;

		for (int i = 0; i <= size1; ++i) {
			vector<int> select(size1, 0);
			for (int j = 0; j < i; ++j)
				select[j] = -1;

			do {
				int sum = 0;
				for (int k = 0; k < size1; ++k) {
					if (select[k] == -1)
						sum += v1[k];
				}
				if (m.count(sum) > 0)
					++m[sum];
				else
					m.insert({ sum,1 });
			} while (next_permutation(select.begin(), select.end()));
		}

		for (int i = 0; i <= size2; ++i) {
			vector<int> select(size2, 0);
			for (int j = 0; j < i; ++j)
				select[j] = -1;

			do {
				int sum = 0;
				for (int k = 0; k < size2; ++k) {
					if (select[k] == -1)
						sum += v2[k];
				}
				if (m.count(k - sum) > 0)
					count += m[k - sum];
			} while (next_permutation(select.begin(), select.end()));
		}
		cout << "#" << t << " " << count << "\n";
	}

	return 0;
}