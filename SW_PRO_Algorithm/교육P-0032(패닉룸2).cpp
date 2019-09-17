#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { 1,0,-1,0 };

// 다익스트라, bfs
struct node {
	int x;
	int y;
	long long cost;

	node(int _x, int _y, long long _cost) {
		x = _x;
		y = _y;
		cost = _cost;
	}
};

struct cmp_node { // top에 가장 작은 수가 가도록 내림차순 정렬
	bool operator()(node t, node u) {
		return t.cost > u.cost;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> arr(n, vector<int>(m));
		vector<vector<long long>> d(n, vector<long long>(m, LONG_MAX));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				cin >> arr[i][j];
		}

		priority_queue<node, vector<node>, cmp_node> q;
		node temp(0, 0, arr[0][0]);
		q.push(temp);
		d[0][0] = arr[0][0];

		while (!q.empty()) {
			int cx = q.top().x;
			int cy = q.top().y;
			q.pop();
			if (cy == n - 1 && cx == m - 1)
				break;
			for (int k = 0; k < 4; ++k) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];

				if (nx < 0 || nx >= m || ny < 0 || ny >= n)
					continue;
				if (d[ny][nx] > d[cy][cx] + arr[ny][nx]) {
					d[ny][nx] = d[cy][cx] + arr[ny][nx];
					node nnode(nx, ny, d[ny][nx]);
					q.push(nnode);
				}
			}
		}

		cout << "#" << t << " " << d[n - 1][m - 1] << "\n";
	}
	return 0;
}