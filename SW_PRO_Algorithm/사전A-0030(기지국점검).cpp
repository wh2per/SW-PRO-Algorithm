#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> info;
vector<pair<long long, int>> dist1;
vector<pair<long long, int>> dist2;
vector<int> finish;

long long ans;
int n, e, c, k, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		cin >> n >> e >> c >> k >> m; // 1~c : 기술센터, c+1~k : 기지국

		info.assign(n + 1, vector<pair<int, int>>());
		dist1.assign(n + 1, { LLONG_MAX,0 });
		dist2.assign(n + 1, { LLONG_MAX,0 });
		finish.assign(n + 1, 0);

		for (int i = 1; i <= e; ++i) { // 간선 정보
			int x, y, z;
			cin >> x >> y >> z;

			info[x].push_back({ y,z });
			info[y].push_back({ x,z });
		}

		priority_queue<pair<long long, pair<int, int>>> pq; // 코스트, <위치, 기술센터번호>
		for (int i = 1; i <= c; ++i) {
			pq.push({ 0,{i,i} });
			dist1[i].first = 0;
		}

		while (!pq.empty()) { // 최선책
			long long cost = -pq.top().first;
			int pos = pq.top().second.first;
			int cnum = pq.top().second.second;
			pq.pop();

			if (cost > dist1[pos].first)
				continue;

			for (auto a : info[pos]) {
				int next = a.first;
				int ncost = a.second;

				if (dist1[next].first > dist1[pos].first + ncost) {
					dist1[next].first = dist1[pos].first + ncost;
					dist1[next].second = cnum;
					pq.push({ -dist1[next].first,{next, cnum} });
				}
			}
		}

		for (int i = c + 1; i <= k; ++i)
			++finish[dist1[i].second];

		for (int i = 1; i <= c; ++i) {
			if (finish[i] <= m) {
				pq.push({ 0,{ i,i } });
				dist2[i].first = 0;
			}
		}

		while (!pq.empty()) { // 최선책
			long long cost = -pq.top().first;
			int pos = pq.top().second.first;
			int cnum = pq.top().second.second;
			pq.pop();

			if (cost > dist2[pos].first)
				continue;

			for (auto a : info[pos]) {
				int next = a.first;
				int ncost = a.second;

				if (dist2[next].first > dist2[pos].first + ncost) {
					dist2[next].first = dist2[pos].first + ncost;
					dist2[next].second = cnum;
					pq.push({ -dist2[next].first,{ next, cnum } });
				}
			}
		}

		ans = 0;
		for (int i = c + 1; i <= k; ++i)
			ans += dist1[i].first;

		if (m < k - c) { // 기지국이 엔지니어 수보다 많을 경우
			priority_queue<pair<long long, pair<long long, long long>>> ci;
			for (int i = c + 1; i <= k; ++i)
				ci.push({ -(dist2[i].first - dist1[i].first), {dist1[i].first, dist2[i].first} });
			for (int i = 0; i < k - c - m; ++i) {
				ans -= ci.top().second.first;
				ans += ci.top().second.second;
				ci.pop();
			}
		}

		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}