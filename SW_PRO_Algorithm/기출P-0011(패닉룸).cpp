#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

// 다익스트라

const int dx[] = { 1,0 };
const int dy[] = { 0,1 };

vector<vector<int>> info;
vector<vector<int>> dist;

struct node {
	int y;
	int x;
};

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

		info.assign(n, vector<int>(m, 0));
		dist.assign(n, vector<int>(m, INT_MAX));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				cin >> info[i][j];
		}

		priority_queue<pair<int, pair<int, int>>> pq;
		dist[0][0] = info[0][0];
		pq.push({ -dist[0][0], {0,0} });

		while (!pq.empty()) {
			int cost = -pq.top().first;
			int y = pq.top().second.first;
			int x = pq.top().second.second;
			pq.pop();
			if (x == m - 1 && y == n - 1)
				break;

			for (int k = 0; k < 2; ++k) {
				int ny = y + dy[k];
				int nx = x + dx[k];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m) // 맵을 벗어날때
					continue;
				if (dist[ny][nx] > dist[y][x] + info[ny][nx]) {
					dist[ny][nx] = dist[y][x] + info[ny][nx];
					pq.push({ -dist[ny][nx],{ny,nx} });
				}
			}
		}

		cout << "#" << t << " " << dist[n - 1][m - 1] << "\n";

	}

	return 0;
}