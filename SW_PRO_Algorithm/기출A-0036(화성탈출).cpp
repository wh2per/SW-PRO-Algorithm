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

	//freopen("./sample_input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, m, k;
		cin >> n >> m >> k;

		memset(check, false, sizeof(check));
		memset(info, false, sizeof(info));

		queue<int> q;
		int ans = 0;

		for (int i = 0; i < k; ++i) {
			int a;
			cin >> a;

			q.push(a);
			check[a] = true;
		}

		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;

			info[a][b] = true;
			info[b][a] = true;
		}

		int temp = 0;
		int pos = 1001;
		while (!q.empty()) {
			int size = q.size();

			temp = pos;
			pos = 1001;
			for (int i = 0; i < size; ++i) {
				int c = q.front();
				q.pop();

				for (int j = 1; j <= n; ++j) {
					if (info[c][j] && !check[j]) {
						q.push(j);
						if (pos > j)
							pos = j;
						check[j] = true;
					}
				}
			}
			++ans;
		}
		if (pos == 1001)
			pos = temp;
		cout << "#" << t << " " << pos << " " << ans - 1 << "\n";
	}


	return 0;
}

