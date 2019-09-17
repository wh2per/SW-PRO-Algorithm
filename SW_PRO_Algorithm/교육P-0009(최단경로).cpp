#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

// ���ͽ�Ʈ��
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int v, e;
		cin >> v >> e;

		vector<vector<pair<int, int>>> info(v + 1, vector<pair<int, int>>());
		vector<int> dist(v + 1, INT_MAX);

		for (int i = 0; i < e; ++i) {
			int u, v, w;
			cin >> u >> v >> w;

			info[u].push_back({ v,w });
			info[v].push_back({u,w });
		}

		priority_queue<pair<int, int>> q;

		q.push({ 0, 1 });	// ������ �߰�
		dist[1] = 0;		// ������ �ִܰŸ�

		while (!q.empty()) {
			int cost = q.top().first;		// ���� ���
			int pos = q.top().second;		// ���� ��ġ

			q.pop();

			for (int i = 0; i < info[pos].size(); ++i) {		// ���� ����Ǿ��ִ� �� ��ȸ
				int next = info[pos][i].first;
				int ncost = info[pos][i].second;

				if (dist[next] > dist[pos] + ncost) {		// �Ÿ��� �����ؾ� �� ���
					dist[next] = dist[pos] + ncost;
					q.push({ -dist[next], next });			// ��� �����ϱ� ���� ť�� ����
				}
			}
		}
		int ans;
		if (dist[v] == INT_MAX)
			ans = -1;
		else
			ans = dist[v];
		cout << "#" << t <<" "<< ans << "\n";
	}
	return 0;
}