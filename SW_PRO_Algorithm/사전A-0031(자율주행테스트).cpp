#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 크루스칼

typedef struct node {
	int x;
	int y;
	int cost;
};

vector<node> info;
int v[10001];

int find(int n)
{
	if (v[n] == n)
		return n;
	v[n] = find(v[n]);
	return v[n];
}

bool cmp_cost(node c1, node c2) {		// 속도가 낮은 순 정렬
	if (c1.cost < c2.cost)
		return true;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, m;
		cin >> n >> m;

		info.clear();

		for (int i = 1; i <= n; ++i)			// 초기화
			v[i] = i;

		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			if (a > b)
				swap(a, b);
			info.push_back({ a,b,c });
		}

		sort(info.begin(), info.end(), cmp_cost);

		int s, e;
		cin >> s >> e;
		int minv = 0;
		int maxv = 0;
		int ans = INT_MAX;

		int left = 0;

		while (left < info.size()) {			// 하한선 찾기
			int p1, p2;
			bool flag = false;

			for (int i = 1; i <= n; ++i)			// 초기화
				v[i] = i;

			for (int i = left; i < info.size(); ++i) {
				p1 = find(info[i].x);
				p2 = find(info[i].y);

				if (p1 == p2)
					continue;
				maxv = max(maxv, info[i].cost);
				v[p1] = p2;

				if (find(s) == find(e)) {
					minv = info[left].cost;
					flag = true;
					break;
				}
			}

			if (flag) {		// 성공했을 경우
				++left;
				ans = min(ans, maxv - minv);
			}
			else
				break;
		}

		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}