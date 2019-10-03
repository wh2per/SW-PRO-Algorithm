#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

// ������

vector<int> discoverd;
vector<int> ans;
int number;
vector<vector<pair<int, int>>> info;
// map<pair<int, int>, int> einfo;

int dfs(int here, int prev) {
	discoverd[here] = ++number;		// Ž�� ���� ����
	int curr = discoverd[here];

	for (int i = 0; i < info[here].size(); ++i) {
		int next = info[here][i].first;

		if (next == prev)		// �θ� �����
			continue;

		if (discoverd[next]) 		// �̹� Ž���� �����϶�
			curr = min(curr, discoverd[next]);
		else {
			int where = dfs(next, here);		// here�� �ڽ� ��尡 �� �� �ִ� ����� ���� ó�� �湮�� ���
			if (where > discoverd[here]) 
				ans.push_back(info[here][i].second);
			curr = min(curr, where);
		}
	}
	return curr;
}

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

		info.assign(n + 1, vector<pair<int,int>>());
		discoverd.assign(n + 1, 0);
		ans.clear();
		number = 0;

		for (int i = 1; i <= m; ++i) {
			int a, b;
			cin >> a >> b;
			info[a].push_back({ b,i });
			info[b].push_back({ a, i });
		}
	
		for (int i = 1; i <= n; ++i) {
		if (!discoverd[i])
			dfs(i, 0);
		}

		sort(ans.begin(), ans.end());
		cout << "#" << t << " " << ans.size() << " ";
		for (auto a : ans)
			cout << a << " ";
		cout << "\n";
	}

	return 0;
}
