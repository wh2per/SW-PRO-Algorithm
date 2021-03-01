#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int dist[100001];
int  friends[100001];
vector<pair<int, int >> info[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int n, m, k;
		cin >> n >> m >> k;

		// 초기화
		for (int i = 1; i <= n; ++i) {
			info[i].clear();
			dist[i] = INT_MAX;
		}
		memset(friends, 0, sizeof(friends));

		// 정보
		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;

			info[b].push_back({ a,c });
		}

		for (int i = 0; i < k; ++i) {
			int a, b;
			cin >> a >> b;

			friends[a] = b;
		}

		priority_queue<pair<int, int>> pq;
		dist[n] = 0;
		pq.push({ 0,n });

		while (!pq.empty()) {
			int cost = -pq.top().first;
			int pos = pq.top().second;
			pq.pop();

			//if (pos == 1)	 //탈출조건 들어가면 안댐
			//	break;
			for (auto a : info[pos]) {
				int next = a.first;
				int ncost = a.second;
				int ndist = dist[pos] + ncost;

				if (ndist > friends[next])
					ndist = ndist - friends[next];
				else
					ndist = 0;

				if (dist[next] > ndist) {
					dist[next] = ndist;
					pq.push({ -ndist, next });
				}
			}
		}

		cout << "#" << tc << " " << dist[1] << "\n";
	}

	return 0;
}