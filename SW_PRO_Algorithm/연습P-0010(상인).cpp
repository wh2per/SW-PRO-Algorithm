#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

int depth[100001];
vector<int> tree[100001];
int parent[100001][20];
int cost[100001][20];
queue<pair<int, int>> q;

long long lca(int u, int v) {
	long long ans = 0;
	if (depth[u] < depth[v])
		swap(u, v);
	int diff = depth[u] - depth[v];

	int j = 0;
	for (j = 19; j >= 0; --j) {        // 깊이 차이만큼 반복
		if (depth[parent[u][j]] >= depth[v]) {
			ans += cost[u][j];
			u = parent[u][j];
		}
	}

	if (u != v) {       // 부모가 같지 않으면
		for (int j = 19; j >= 0; --j) {
			if (parent[u][j] != 0 && parent[u][j] != parent[v][j]) {        // 부모가 있으면서 공통부모가 아니면
				ans += cost[u][j];
				ans += cost[v][j];
				u = parent[u][j];           // 부모로 이동
				v = parent[v][j];
			}
		}
		ans += cost[u][0];
		ans += cost[v][0];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n;
		cin >> n;

		fill(depth, depth + n + 1, -1);
		for (int i = 0; i <= n; ++i) {
			tree[i].clear();
			for (int j = 0; j < 20; ++j) {
				parent[i][j] = 0;
				cost[i][j] = 0;
			}
		}
		for (int i = 0; i < n - 1; ++i) {
			int a, b;
			cin >> a >> b;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}


		q.push({ 1,0 });
		while (!q.empty()) {
			int pos = q.front().first;
			int dpt = q.front().second;
			q.pop();

			depth[pos] = dpt;
			for (auto a : tree[pos]) {
				if (depth[a] == -1) {
					parent[a][0] = pos;
					cost[a][0] = 1;
					q.push({ a,dpt + 1 });
				}
			}
		}

		for (int j = 1; j < 20; ++j) {
			for (int i = 1; i <= n; ++i) {
				parent[i][j] = parent[parent[i][j - 1]][j - 1];     // parent[i][j] = i의 2^j번째 부모번호를 저장
				if (cost[parent[i][j - 1]][j - 1] != 0)
					cost[i][j] = cost[i][j - 1] + cost[parent[i][j - 1]][j - 1];                // cost[i][j] = i의 2^j번째 부모에 가는 비용을 저장
			}
		}

		long long ans = 0;
		for (int i = 1; i < n; ++i)
			ans += lca(i, i + 1);

		cout << "#" << test << " " << ans << "\n";


	}
	return 0;
}
