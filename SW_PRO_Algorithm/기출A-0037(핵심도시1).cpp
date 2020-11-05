#include <iostream>
#include <string.h>
#include <climits>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int discoverd[100001];
//vector<int> discoverd;
bool ans[100001];
//vector<bool> ans;
vector<vector<int>> info;
int number;
int sum;

int dfs(int here, bool isroot) {
	discoverd[here] = ++number;		// Ž�� ���� ����
	int curr = discoverd[here];

	int child = 0;
	for (int i = 0; i < info[here].size(); ++i) {
		int next = info[here][i];

		if (discoverd[next]) 		// �̹� Ž���� �����϶�
			curr = min(curr, discoverd[next]);
		else {
			++child;
			int prev = dfs(next, false);		// Ž������ ���� �����̸� dfs����
			if (!isroot && prev >= discoverd[here])
				ans[here] = true;

			curr = min(curr, prev);
		}
	}

	if (isroot && child >= 2)
		ans[here] = true;

	return curr;
}

int main() {
	freopen("sample_input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int v, e;
		cin >> v >> e;


		info.assign(v + 1, vector<int>());
		memset(discoverd, 0, sizeof(discoverd));
		//discoverd.assign(v + 1, 0);
		memset(ans, false, sizeof(ans));
		//ans.assign(v + 1, false);

		sum = 0;
		number = 0;

		for (int i = 0; i < e; ++i) {
			int a, b;
			cin >> a >> b;

			info[a].push_back(b);
			info[b].push_back(a);
		}

		for (int i = 1; i <= v; ++i) {
			if (!discoverd[i])
				dfs(i, true);
		}

		for (int i = 1; i <= v; ++i) {
			if (ans[i])
				++sum;
		}
		cout << "#" << t << " " << sum << " ";
		for (int i = 1; i <= v; ++i) {
			if (ans[i])
				cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}