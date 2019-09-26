#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string.h>
#include <queue>
using namespace std;

// 다익스트라

vector<vector<long long>> dist;
vector<vector<pair<int, int>>> info;

struct node {
	long long cost;
	int pos;
	int ticket;
};

struct cmp_node {
	bool operator()(node a, node b) {
		if (a.cost < b.cost)
			return true;
		else if (a.cost == b.cost) {
			if (a.ticket > b.ticket)
				return true;
			else
				return false;
		}
		else
			return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input2.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, m, k;
		cin >> n >> m >> k;

		dist.assign(n + 1, vector<long long>(3, LLONG_MAX));
		info.assign(n + 1, vector<pair<int, int>>());

		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;

			info[a].push_back({ b,c });
			info[b].push_back({ a,c });
		}

		priority_queue<node, vector<node>, cmp_node> q;

		int s, e;
		cin >> s >> e;

		dist[s][0] = 0;		// 티켓 0개
		dist[s][1] = 0;		// 티켓 1개
		dist[s][2] = 0;		// 티켓 2개
		q.push({ 0,s,k });

		while (!q.empty()) {
			long long cost = -q.top().cost;
			int pos = q.top().pos;
			int ticket = q.top().ticket;
			q.pop();

			if (pos == e)
				break;

			for (int i = 0; i < info[pos].size(); ++i) {
				int next = info[pos][i].first;
				long long ncost = info[pos][i].second;
				
				// 기본 이동
				if (dist[next][ticket] > dist[pos][ticket] + ncost) {		// 거리를 갱신해야 할 경우
					dist[next][ticket] = dist[pos][ticket] + ncost;
					q.push({ -dist[next][ticket], next, ticket });			// 계속 진행하기 위해 큐에 삽입
				}
				// 티켓 사용
				if (ticket > 0) {
					if (dist[next][ticket-1] > dist[pos][ticket] + 1) {		// 거리를 갱신해야 할 경우
						dist[next][ticket-1] = dist[pos][ticket] + 1;
						q.push({ -dist[next][ticket - 1], next, ticket - 1 });			// 계속 진행하기 위해 큐에 삽입
					}
				}
			}
		}
		long long ans = LLONG_MAX;
		for (int i = 0; i < 3; ++i) {
			if (dist[e][i] != LLONG_MAX && ans>dist[e][i])
				ans = dist[e][i];
		}
		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}
