#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// 벨만포드

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

		int m; // 운석 갯수
		cin >> m;
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			arr[b][a] = 1; // 운석은 1
		}

		int w;
		cin >> w;
		for (int i = 0; i < w; ++i) {
			int a, b, c, d, wt;
			cin >> a >> b >> c >> d >> wt;
			arr[b][a] = 2; // 워프는 2
			info[b][a] = { wt,{d,c} };
		}

		dist[0][0] = 0; // 시작점
		bool flag = false;
		for (int i = 1; i <= x * y; ++i) { // 간선만큼 돌려보기
			for (int j = 0; j < y; ++j) { // 정점 완전 탐색
				for (int k = 0; k < x; ++k) {
					if (dist[j][k] == INT64_MAX) // 아직 갱신된 곳이 아니면 스킵
						continue;
					if (j == y - 1 && k == x - 1) // 도착지점은 검사 x
						continue;
					if (arr[j][k] == 1) // 운석은 스킵
						continue;
					else if (arr[j][k] == 2) { // 워프일때
						int wy = info[j][k].second.first;
						int wx = info[j][k].second.second;
						int wt = info[j][k].first;

						if (dist[wy][wx] > dist[j][k] + wt) {
							if (i != x * y)
								dist[wy][wx] = dist[j][k] + wt;
							else // 음수 사이클 검사
								flag = true;
						}
					}
					else { // 기본 이동
						for (int d = 0; d < 4; ++d) {
							int ny = j + dy[d];
							int nx = k + dx[d];

							if (ny < 0 || ny >= y || nx < 0 || nx >= x || arr[ny][nx] == 1)
								continue;
							if (dist[ny][nx] > dist[j][k] + 1) {
								if (i != x * y)
									dist[ny][nx] = dist[j][k] + 1;
								else // 음수 사이클 검사
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