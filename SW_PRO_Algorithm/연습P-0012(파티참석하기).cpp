#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> info1;
vector<vector<pair<int, int>>> info2;
vector<int> dist1;
vector<int> dist2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input2.txt", "r", stdin);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n, m, x;
		cin >> n >> m >> x;

		info1.assign(n + 1, vector<pair<int, int>>());
		info2.assign(n + 1, vector<pair<int, int>>());
		dist1.assign(n + 1, INT_MAX);
		dist2.assign(n + 1, INT_MAX);
		priority_queue<pair<int, int>> pq;

		for (int i = 0; i < m; ++i) {
			int s, e, t;
			cin >> s >> e >> t;

			info1[s].push_back({e,t});
			info2[e].push_back({s,t });
		}

		dist1[x] = 0;
		pq.push({ 0,x });
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int pos = pq.top().second;
			pq.pop();

			for (auto a : info1[pos]) {
				int next = a.first;
				int ncost = a.second;

				if (dist1[next] > dist1[pos] + ncost) {
					dist1[next] = dist1[pos] + ncost;
					pq.push({-dist1[next], next});
				}
			}
		}

		dist2[x] = 0;
		pq.push({ 0,x });
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int pos = pq.top().second;
			pq.pop();

			for (auto a : info2[pos]) {
				int next = a.first;
				int ncost = a.second;

				if (dist2[next] > dist2[pos] + ncost) {
					dist2[next] = dist2[pos] + ncost;
					pq.push({ -dist2[next], next });
				}
			}
		}

		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if(dist1[i] != INT_MAX && dist2[i] != INT_MAX)
				ans = max(ans, dist1[i] + dist2[i]);
		}

		cout << "#" << test<< " "<<ans<<"\n";
	}
	return 0;
}