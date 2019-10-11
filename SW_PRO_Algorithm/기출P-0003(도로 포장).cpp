#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

// 크루스칼

int n;
int ans;

typedef struct node {
	int x;
	int y;
	int cost;
};

vector<node> info;
int v[351];

int find(int num)
{
	if (v[num] == num)
		return num;
	return v[num] = find(v[num]);
}

bool cmp_cost(node c1, node c2) {       // 속도가 낮은 순 정렬
	if (c1.cost < c2.cost)
		return true;
	else
		return false;
}

int Kruscal_front(int start) {
	int p1, p2;
	int cnt = 0;
	for (int i = 1; i <= n; ++i)            // 초기화
		v[i] = i;

	for (int i = start; i < info.size(); ++i) {
		p1 = find(info[i].x);
		p2 = find(info[i].y);

		if (p1 == p2)
			continue;
		v[p1] = p2;
		++cnt;
		if (cnt == n - 1)
			return i;
	}
	return -1;
}

int Kruscal_back(int start) {
	int p1, p2;
	int cnt = 0;
	for (int i = 1; i <= n; ++i)            // 초기화
		v[i] = i;

	for (int i = start; i>= 0; --i) {
		p1 = find(info[i].x);
		p2 = find(info[i].y);

		if (p1 == p2)
			continue;
		v[p1] = p2;
		++cnt;
		if (cnt == n - 1)
			return i;
	}
	return -1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input2.txt", "r", stdin);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		cin >> n;

		int m;
		cin >> m;

		info.clear();
		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			info.push_back({ a,b,c });
		}
		sort(info.begin(), info.end(), cmp_cost);

		ans = info.back().cost - info.front().cost;

		int start = 0;
		while (1) {
			int end = Kruscal_front(start);
			if (end != -1)
				ans = min(ans, info[end].cost - info[start].cost);
			else
				break;
			start = end;
			end = Kruscal_back(start);
			if (end != -1)
				ans = min(ans, info[start].cost - info[end].cost);
			else
				break;
			start = end + 1;
		}

		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}

