#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int v, e;
		cin >> v >> e;

		vector<vector<pair<int, int>>> info(v + 1, vector<pair<int, int>>());
		vector<int> dist(v + 1, INT_MAX);

		for (int i = 0; i < e; ++i) {
			int u, v, w;
			cin >> u >> v >> w;

			info[u].push_back({ v,w });
			info[v].push_back({u,w });
		}

		priority_queue<pair<int, int>> q;

		q.push({ 0, 1 });	// 시작점 추가
		dist[1] = 0;		// 시작점 최단거리

		while (!q.empty()) {
			int cost = q.top().first;		// 현재 비용
			int pos = q.top().second;		// 현재 위치

			q.pop();

			for (int i = 0; i < info[pos].size(); ++i) {		// 나와 연결되어있는 곳 순회
				int next = info[pos][i].first;
				int ncost = info[pos][i].second;

				if (dist[next] > dist[pos] + ncost) {		// 거리를 갱신해야 할 경우
					dist[next] = dist[pos] + ncost;
					q.push({ -dist[next], next });			// 계속 진행하기 위해 큐에 삽입
				}
			}
		}
		int ans;
		if (dist[v] == INT_MAX)
			ans = -1;
		else
			ans = dist[v];
		cout << "#" << t <<" "<< ans << "\n";
	}
	return 0;
}