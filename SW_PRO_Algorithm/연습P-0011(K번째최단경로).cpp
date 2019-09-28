#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
using namespace std;

// 다익스트라

vector<pair<int, long long>> info[100001];
vector<int> dist;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, m, k;
		cin >> n >> m >> k;

		for (int i = 0; i <= n; ++i)
			info[i].clear();

		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			info[a].push_back({ b,c });
			info[b].push_back({ a,c });
		}

		priority_queue<pair<long long, int>> pq;
		dist.assign(n + 1, 0);		// 몇 명 도착했는지 저장용

		pq.push({ 0,1 });

		long long ans = 0;
		while (!pq.empty()) {
			long long cost = -pq.top().first;
			int pos = pq.top().second;
			pq.pop();

			if (dist[pos] == k+1) 		// 이미 K명 도착했다면 진행 x
				continue;
			if (dist[n] == k) { 		// k번째 도착
				ans = cost;
				break;
			}
			++dist[pos];				// 도착한 사람 증가
			for (auto a : info[pos])
				pq.push({ -(cost + a.second),a.first });
		}

		cout << "#" << t << " ";
		if (dist[n] == k)
			cout << ans << "\n";
		else
			cout << "-1\n";

	}

	return 0;
}