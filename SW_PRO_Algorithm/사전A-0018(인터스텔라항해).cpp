#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// ��������

vector<vector<int>> arr;
vector<vector<long long>> dist;

const int dx[] = { 1,0, -1, 0 };
const int dy[] = { 0,1, 0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int x, y;
		cin >> x >> y;

		arr.assign(y, vector<int>(x, 0));
		dist.assign(y, vector<long long>(x, INT64_MAX));
		pair<int, pair<int, int>> info[31][31];

		int m; // � ����
		cin >> m;
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			arr[b][a] = 1; // ��� 1
		}

		int w;
		cin >> w;
		for (int i = 0; i < w; ++i) {
			int a, b, c, d, wt;
			cin >> a >> b >> c >> d >> wt;
			arr[b][a] = 2; // ������ 2
			info[b][a] = { wt,{d,c} };
		}

		dist[0][0] = 0; // ������
		bool flag = false;
		for (int i = 1; i <= x * y; ++i) { // ������ŭ ��������
			for (int j = 0; j < y; ++j) { // ���� ���� Ž��
				for (int k = 0; k < x; ++k) {
					if (dist[j][k] == INT64_MAX) // ���� ���ŵ� ���� �ƴϸ� ��ŵ
						continue;
					if (j == y - 1 && k == x - 1) // ���������� �˻� x
						continue;
					if (arr[j][k] == 1) // ��� ��ŵ
						continue;
					else if (arr[j][k] == 2) { // �����϶�
						int wy = info[j][k].second.first;
						int wx = info[j][k].second.second;
						int wt = info[j][k].first;

						if (dist[wy][wx] > dist[j][k] + wt) {
							if (i != x * y)
								dist[wy][wx] = dist[j][k] + wt;
							else // ���� ����Ŭ �˻�
								flag = true;
						}
					}
					else { // �⺻ �̵�
						for (int d = 0; d < 4; ++d) {
							int ny = j + dy[d];
							int nx = k + dx[d];

							if (ny < 0 || ny >= y || nx < 0 || nx >= x || arr[ny][nx] == 1)
								continue;
							if (dist[ny][nx] > dist[j][k] + 1) {
								if (i != x * y)
									dist[ny][nx] = dist[j][k] + 1;
								else // ���� ����Ŭ �˻�
									flag = true;
							}
						}
					}
				}
			}
		}

		cout << "#" << t << " ";
		if (flag)
			cout << "mininf\n";
		else {
			if (dist[y - 1][x - 1] == INT64_MAX)
				cout << "noway\n";
			else
				cout << dist[y - 1][x - 1] << "\n";
		}
	}

	return 0;
}