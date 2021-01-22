#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAX = 300001;
int ans[MAX], fw[MAX];
pair<int, int> p[MAX];

struct Q {
	int a, b, c, i;
}q[MAX];

bool comp(const Q& q1, const Q& q2) {		// 키순 정렬
	return q1.c > q2.c;
}

void update(int idx) {
	while (idx <= MAX) {
		fw[idx]++;
		idx += idx & -idx;
	}
}

int query(int idx) {
	int val = 0;
	while (idx) {
		val += fw[idx];
		idx -= idx & -idx;
	}
	return val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("sample_input.txt", "r", stdin);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int n, m;
		cin >> n >> m;
		memset(fw, 0, sizeof(fw));

		for (int i = 1; i <= n; ++i) {
			cin >> p[i].first;
			p[i].second = i;
		}

		for (int i = 0; i < m; ++i) {
			cin >> q[i].a >> q[i].b >> q[i].c;
			q[i].i = i;
		}

		sort(p + 1, p + n + 1);
		sort(q, q + m, comp);

		for (int i = 0; i < m; ++i) {
			while (n && p[n].first > q[i].c)
				update(p[n--].second);
			ans[q[i].i] = query(q[i].b) - query(q[i].a - 1);
		}
		cout << "#" << t << " ";
		for (int i = 0; i < m; ++i)
			cout << ans[i] << " ";
		cout << "\n";
	}

	return 0;
}