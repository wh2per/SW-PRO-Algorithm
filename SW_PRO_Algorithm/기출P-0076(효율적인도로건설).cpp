#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <climits>
using namespace std;

vector<pair<int, int>> info[50001];
int dist1[50001];
int dist2[50001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("./sample_input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, m;
		cin >> n >> m;

		//info.assign(50001,pair<int,int>());
		for (int i = 1; i <= n; ++i) {
			info[i].clear();
			dist1[i] = INT_MAX;
			dist2[i] = INT_MAX;
		}
		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;

			info[a].push_back({ b,c });
			info[b].push_back({ a,c });
		}

		dist1[1] = 0;
		priority_queue<pair<int, int>> pq;
		pq.push(make_pair(0, 1));
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int pos = pq.top().second;
			pq.pop();

			if (cost > dist1[n])
				continue;

			for (int i = 0; i < info[pos].size(); ++i) {
				int next = info[pos][i].first;
				int ncost = info[pos][i].second;

				if (dist1[next] > dist1[pos] + ncost) {
					dist1[next] = dist1[pos] + ncost;
					pq.push({ -dist1[next], next });
				}
			}
		}

		dist2[n] = 0;
		pq.push(make_pair(0, n));
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int pos = pq.top().second;
			pq.pop();

			if (cost > dist2[1])
				continue;

			for (int i = 0; i < info[pos].size(); ++i) {
				int next = info[pos][i].first;
				int ncost = info[pos][i].second;

				if (dist2[next] > dist2[pos] + ncost) {
					dist2[next] = dist2[pos] + ncost;
					pq.push({ -dist2[next], next });
				}
			}
		}
		int limit = dist1[n] - 2;		// Çã¿ëÄ¡
		int ans = 0;
		sort(dist1, dist1 + n);
		sort(dist2, dist2 + n);

		for (int i = 2; i <= n; ++i) {
			if (dist1[i] >= limit)
				break;
			int pos = upper_bound(dist2, dist2 + n - 1, limit - dist1[i]) - dist2;
			if (pos != 0)
				ans += pos - 1;
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}

