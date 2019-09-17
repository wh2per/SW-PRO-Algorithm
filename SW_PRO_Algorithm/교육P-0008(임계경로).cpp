#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
// 위상 정렬

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int n, m, ans = 0;
		cin >> n >> m;

		vector<vector<int>> info(n + 1);
		map<pair<int, int>, int> cost_info;
		vector<int> degree(n+1);
		vector<int> cost(n + 1);

		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b>>c;
			info[a].push_back(b);
			if (cost_info.count({ a,b }) > 0) {
				if (cost_info[{a, b}] < c)
					cost_info[{a, b}] = c;
			}else
				cost_info.insert({ {a,b},c });
			++degree[b];
		}

		queue<int> q;
		for (int i = 1; i <= n; ++i) {		// 차수가 0인 정점 push
			if (degree[i] == 0)
				q.push(i);
		}
		
		while (!q.empty()) {
			int d = q.front();
			q.pop();
			for (auto a : info[d]) {
				--degree[a];
				cost[a] = max(cost[d] + cost_info[{d,a}], cost[a]);
				if (degree[a] == 0)
					q.push(a);
			}
		}
		cout << "#" << t << " " << cost[n] << "\n";
	}
	return 0;
}
