#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string.h>
using namespace std;

int n, m, k;
int reco[1001];
bool bad[1001];
bool check[1001];
int ans;

void dfs(int who, int dcnt, int bcnt) {
	check[who] = true;

	if (bad[who])
		++bcnt;

	if (bcnt > k)
		return;

	++dcnt;

	if (!check[reco[who]])
		dfs(reco[who], dcnt, bcnt);

	if (ans < dcnt)
		ans = dcnt;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("sample_input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cin >> n >> m >> k;

		memset(reco, 0, sizeof(reco));
		memset(bad, false, sizeof(bad));

		ans = 0;

		for (int i = 1; i <= n; ++i)
			cin >> reco[i];

		for (int i = 0; i < m; ++i) {
			int a;
			cin >> a;
			bad[a] = true;
		}

		for (int i = 1; i <= n; ++i) {
			memset(check, false, sizeof(check));
			dfs(i, 0, 0);
		}

		cout << "#" << t << " " << ans << "\n";
	}


	return 0;
}