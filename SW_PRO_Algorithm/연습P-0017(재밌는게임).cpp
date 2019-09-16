#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <map>
#include <set>
using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
//int arr[101][101];
//int check[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	
	for (int t = 1; t <= tc; ++t) {
		int n, m, ans = INT_MAX;
		cin >> n >> m;

		vector<vector<int>> arr(n, vector<int>(m));
		vector<vector<int>> check(n, vector<int>(m, 0));
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				cin >> arr[i][j];
		}
		int num = 1;
		for (int i = 0; i < n; ++i) {				// ±×·ìÈ­
			for (int j = 0; j < m; ++j) {
				if (check[i][j] == 0) {
					queue<pair<int, int>> q;
					check[i][j] = num;
					q.push({ i,j });

					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						q.pop();

						for (int k = 0; k < 4; ++k) {
							int nx = x + dx[k];
							int ny = y + dy[k];

							if (nx >= m || nx<0 || ny >= n || ny < 0 || check[ny][nx]!=0 || arr[ny][nx] != arr[y][x])
								continue;
							q.push({ ny,nx });
							check[ny][nx] = num;
						}
					}
					++num;
				}
			}
		}
		vector<set<int>> graph(num, set<int>());
		for (int g = 1; g < num; ++g) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (check[i][j] == g) {
						for (int k = 0; k < 4; ++k) {
							int nx = j + dx[k];
							int ny = i + dy[k];

							if (nx >= m || nx<0 || ny >= n || ny < 0 || check[ny][nx] == g)
								continue;
							graph[g].insert(check[ny][nx]);
							graph[check[ny][nx]].insert(g);
						}
					}
				}
			}
		}
		for (int i = 1; i < num; ++i) {
			queue<pair<int,int>> q;
			int ac = 0;
			vector<bool> visited(num, false);

			visited[i] = true;
			q.push({i,0});
			while (!q.empty()){
				int pos = q.front().first;
				int count = q.front().second;
				if (count > ac)
					ac = count;
				q.pop();

				for (auto a : graph[pos]) {
					if (!visited[a]) {
						q.push({a,count+1});
						visited[a] = true;
					}
				}
			}
			if (ac < ans)
				ans = ac;
		}
		
		
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}