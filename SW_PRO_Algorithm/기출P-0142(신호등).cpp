#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct datas {
	int pos;
	int cost;
};

struct datas2 {
	int cost;
	int pos;
	int ticket;
};

bool operator<(datas2 t, datas2 u) {
	return t.cost > u.cost;
}

int n, m, k, tc;
vector<datas> info[40001];
int dist[40001][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);

	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cin >> n >> m >> k;

		for (int i = 1; i <= n; ++i) {
			info[i].clear();
			dist[i][0] = INT_MAX;
			dist[i][1] = INT_MAX;
		}

		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;

			info[a].push_back({ b,c });
			info[b].push_back({ a,c });
		}

		dist[1][0] = 0;
		priority_queue<datas2, vector<datas2>> pq;
		pq.push({ 0,1,0 });

		while (!pq.empty()) {
			int cost = pq.top().cost;
			int pos = pq.top().pos;
			int ticket = pq.top().ticket;
			pq.pop();

			if (cost >= min(dist[n][0], dist[n][1]))
				break;

			bool flag = (cost / k) % 2;

			for (int i = 0; i < info[pos].size(); ++i) {
				int next = info[pos][i].pos;
				int ncost = info[pos][i].cost;


				if (!flag) {		// 초록불
					if (dist[next][ticket] > cost + ncost) {
						dist[next][ticket] = cost + ncost;
						pq.push({ dist[next][ticket], next,ticket });
					}
				}
				else {		// 빨간불
					if (ticket == 0) {
						if (dist[next][ticket + 1] > cost + ncost) {
							dist[next][ticket + 1] = cost + ncost;
							pq.push({ dist[next][ticket + 1], next, ticket + 1 });
						}
					}
				}
			}
			if (flag) {
				int ncost = k * ((cost / k)) + k;
				pq.push({ ncost, pos,ticket });
			}
		}
		cout << "#" << t << " " << min(dist[n][0], dist[n][1]) << "\n";
	}
	return 0;
}