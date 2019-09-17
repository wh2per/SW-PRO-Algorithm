#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

// LCA

vector<vector<int>> tree;
vector<int> depth;
vector<vector<int>> parent;
int d;

void dfs(int now, int dpt) {
	depth[now] = dpt;

	for (auto a : tree[now]) {
		if (depth[a] == -1) {
			parent[a][0] = now;
			dfs(a, dpt + 1);
		}
	}
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

		tree.assign(n + 1, vector<int>());
		depth.assign(n + 1, -1);
		parent.assign(n + 1, vector<int>(20, 0));

		for (int i = 2; i <= n; ++i) {
			int p;
			cin >> p;
			tree[p].push_back(i);
			tree[i].push_back(p);
		}
		dfs(1, 0);

		for (int j = 1; j < 20; ++j) {
			for (int i = 1; i <= n; ++i)
				parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
		cout << "#" << t << " ";

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			if (depth[u] < depth[v])
				swap(u, v);
			int diff = depth[u] - depth[v]; // 깊이 차이
			for (int j = 0; diff; j++) {
				if (diff % 2) // 홀수면 바로 부모를 불러오기
					u = parent[u][j]; // 짝수면 나누기를 통해 접근
				diff /= 2;
			}
			if (u != v) { // 부모가 같지 않으면
				for (int j = 19; j >= 0; --j) {
					if (parent[u][j] != 0 && parent[u][j] != parent[v][j]) {
						u = parent[u][j];
						v = parent[v][j];
					}
				}
				u = parent[u][0];
			}
			cout << u << " ";
		}
		cout << "\n";
	}
	return 0;
}
