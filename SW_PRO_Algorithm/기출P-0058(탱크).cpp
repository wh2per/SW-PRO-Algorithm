#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAX = 100000;
const int MAX_XY = 1000000;

struct Tank {
	int x, y, n;
}tank[MAX + 1];

long long tree[MAX_XY + 1];

bool comp(const Tank& tank1, const Tank& tank2) {
	return tank1.x > tank2.x;
}

void update(int x, int v) {
	while (x <= MAX_XY) {
		tree[x] += (long long)v;
		x += (x & -x);
	}
}

long long query(int x) {
	long long sum = 0;
	while (x > 0) {
		sum += tree[x];
		x -= (x & -x);
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("sample_input.txt", "r", stdin);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int n;
		cin >> n;

		memset(tree, 0, sizeof(tree));

		for (int i = 0; i < n; ++i)
			cin >> tank[i].x >> tank[i].y >> tank[i].n;

		sort(tank, tank + n, comp);

		long long num = 0;
		long long ynum;
		long long sum = 0;

		for (int i = 0; i < n; ++i) {
			ynum = query(tank[i].y - 1);
			sum += (num - ynum);
			num += (long long)tank[i].n;
			update(tank[i].y, tank[i].n);
		}

		cout << "#" << t << " " << sum << "\n";
	}

	return 0;
}

