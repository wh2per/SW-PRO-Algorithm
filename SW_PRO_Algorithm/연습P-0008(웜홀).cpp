#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// 벨만 포드 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int n,m,w;
		cin >> n >> m >> w;

		vector<vector<pair<int, int>>> info(n + 1, vector<pair<int, int>>());
		
		for (int i = 0; i < m; ++i) {		// 일반 양방향
			int u, v, c;
			cin >> u >> v >> c;

			info[u].push_back({ v,c });
			info[v].push_back({ u,c });
		}

		for (int i = 0; i < w; ++i) {		// 웜홀 단방향
			int u, v, c;
			cin >> u >> v >> c;

			info[v].push_back({ u,-c });
		}

		vector<int> dist(n + 1, INT_MAX);
		dist[1] = 0;
		bool flag = false;

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int k = 0; k < info[j].size(); ++k) {
					if (dist[info[j][k].first] == INT_MAX)
						continue;
					if (dist[j] > dist[info[j][k].first] + info[j][k].second) {
						dist[j] = dist[info[j][k].first] + info[j][k].second;
						if (i == n) {
							flag = true;
							break;
						}
					}
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
		
		if(flag)
			cout << "#" << t << " YES" << "\n";
		else
			cout << "#" << t << " NO" << "\n";
	}
	return 0;
}