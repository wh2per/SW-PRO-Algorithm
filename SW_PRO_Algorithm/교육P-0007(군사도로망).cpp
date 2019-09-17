#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

// 크루스칼 알고리즘
vector<int> v;

struct info {
	int x;
	int y;
	int cost;
};

bool cmp_cost(info c1, info c2) {
	if (c1.cost < c2.cost)
		return true;
	else
		return false;
}

int find(int n)
{
	if (v[n] == n)
		return n;
	v[n] = find(v[n]);
	return v[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<info> ci;
		long long sum = 0;
		for (int i = 0; i < m; ++i) {
			info s;
			cin >> s.x >> s.y >> s.cost;
			sum += s.cost;
			s.cost *= -1;
			ci.push_back(s);
		}

		for (int i = 0; i < k; ++i) {
			info s;
			cin >> s.x >> s.y >> s.cost;
			ci.push_back(s);
		}

		sort(ci.begin(), ci.end(), cmp_cost);		// 비용이 낮은 순 정렬

		v.assign(n + 1, 0);
		for (int i = 1; i <= n; ++i)		// 현재 자신의 수로 초기화
			v[i] = i;

		long long ans = 0;
		int p1, p2;
		for (int i = 0; i<ci.size(); i++) {
			p1 = find(ci[i].x);
			p2 = find(ci[i].y);

			if (p1 == p2)		// 사이클이 형성되므로 스킵
				continue;

			v[p1] = p2;			// 채택
			if (ci[i].cost > 0)
				ans += ci[i].cost;
			else
				sum += ci[i].cost;
		}
		cout << "#" << t << " " << ans + sum << "\n";
	}
	return 0;
}