#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string.h>
#include <set>
using namespace std;

vector<vector<int> > info;
int ans[12];
int n, m;

void dfs(int pos, int cm) {
	ans[pos] = cm + 1;

	for (int i = 0; i < info[pos].size(); ++i) {
		if (ans[info[pos][i]] == 0 || ans[info[pos][i]] < ans[pos] + 1)
			dfs(info[pos][i], ans[pos]);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("sample_input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cin >> n >> m;

		info.assign(n + 1, vector<int>());
		vector<int> cnt(n + 1);
		memset(ans, 0, sizeof(ans));

		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			info[b].push_back(a);
			++cnt[a];
		}

		for (int i = 1; i <= n; ++i) {
			if (cnt[i] == 0)
				dfs(i, 0);
		}

		cout << "#" << t << " ";
		for (int i = 1; i <= n; ++i)
			cout << ans[i] << " ";
		cout << "\n";
	}

	return 0;
}