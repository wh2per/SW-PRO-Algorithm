#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int v, e, s;
bool edge[101][101];
bool check[101];

void dfs(int s) {
	if (check[s])
		return;
	cout << s << " ";
	check[s] = true;
	for (int i = 1; i <= v; ++i) {
		if (edge[s][i] && !check[i])
			dfs(i);
	}
}

void bfs(int s) {
	queue<int> q;
	q.push(s);
	check[s] = true;

	while (!q.empty()) {
		int c = q.front();
		q.pop();
		cout << c << " ";

		for (int i = 1; i <= v; ++i) {
			if (edge[c][i] && !check[i]) {
				q.push(i);
				check[i] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("./sample_input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {

		cin >> v >> e >> s;

		memset(edge, false, sizeof(edge));
		memset(check, false, sizeof(check));

		for (int i = 0; i < e; ++i) {
			int start, end;
			cin >> start >> end;

			edge[start][end] = true;
			edge[end][start] = true;
		}

		cout << "#" << t << " ";

		memset(check, false, sizeof(check));
		dfs(s);
		cout << "\n";
		memset(check, false, sizeof(check));
		bfs(s);
		cout << "\n";
	}


	return 0;
}