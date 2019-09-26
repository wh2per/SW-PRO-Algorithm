#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
#include <string.h>
using namespace std;

// 플로이드워셜

long long info[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n;
		cin >> n;

		memset(info, -1, sizeof(info));

		vector<int> del(n);					// 제거할 정점 순서
		vector<bool> check(n + 1, false);	// 사용 가능 정점
		
		for (int i = 0; i < n; ++i) {
			cin >> del[i];
			info[i + 1][i + 1] = 0;
		}

		for (int i = 1; i <= n-1; ++i) {	// 간선 정보 저장
			for (int j = i + 1; j <= n; ++j) {
				long long w;
				cin >> w;
				if (w != 0) {
					info[i][j] = w;
					info[j][i] = w;
				}
			}
		}

		stack<long long> ans;
		cout << "#" << t << " ";
		
		for (int y = n - 1; y >= 0; --y) {		// 경유
			int i = del[y];
			check[i] = true;
			long long big = 0;
			for (int j = 1; j <= n; ++j) {	// 시작점
				if (info[j][i] == -1)		//  시작-경유 가는길이 없으면
					continue;
				for (int k = 1; k <= n; ++k) { 	// 도착점
					if (info[i][k] == -1 || j == k)			// 경유-도착 가는길이 없거나 시작=도착이면
						continue;
					
					if (info[j][k] == -1 || info[j][k] > info[j][i] + info[i][k])  		// 시작-도착 길이 없거나 경유하는 것보다 클때
						info[j][k] = info[j][i] + info[i][k];
					if (check[j] && check[k] && big < info[j][k])
						big = info[j][k];
				}
			}
			for (int j = 1; j <= n; ++j) {
				for (int k = 1; k <= n; ++k) {
					if (check[j] && check[k] && big < info[j][k])
						big = info[j][k];
				}
			}
			ans.push(big);
		}
	
		while (!ans.empty()) {
			cout << ans.top() << " ";
			ans.pop();
		}
		cout << "\n";
	}
	
	return 0; 
}