#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int P_0022() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n;
		cin >> n;

		stack<pair<long, long>> s;
		long long ans = 0;

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;

			if (s.empty())				// ������� ��
				s.push({ i,num });
			else {
				if (s.top().second > num) {		// ���� ž�� ������
					int index = 0;
					while (!s.empty() && s.top().second > num) {		// ��� ������
						pair<long, long> pos = s.top();
						index = pos.first;
						s.pop();
						long long nsize = (i - pos.first)*pos.second;
						if (ans < nsize)
							ans = nsize;
					}
					s.push({ index, num });
				}
				else			// ������ ���ų� ���� ž�� ������
					s.push({ i,num });
			}
		}

		while (!s.empty()) {		// ��� ������
			pair<long, long> pos = s.top();
			s.pop();
			long long nsize = (n - pos.first)*pos.second;
			if (ans < nsize)
				ans = nsize;
		}

		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}