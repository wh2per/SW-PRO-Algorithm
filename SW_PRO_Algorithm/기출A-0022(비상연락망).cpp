#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

bool check[1001];
bool info[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("./sample_input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, m, s;
		cin >> n >> m >> s;

		memset(check, false, sizeof(check));
		memset(info, false, sizeof(info));
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;

			info[a][b] = true;
			info[b][a] = true;
		}

		queue<int> q;
		q.push(s);
		check[s] = true;
		int cnt = 1;
		int ans = 0;

		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				int c = q.front();
				q.pop();

				for (int j = 1; j <= n; ++j) {
					if (info[c][j] && !check[j]) {
						q.push(j);
						++cnt;
						check[j] = true;
					}
				}
			}
			++ans;
		}

		cout << "#" << t << " ";
		if (cnt != n)
			cout << -1 << "\n";
		else
			cout << ans - 1 << "\n";
	}


	return 0;
}

