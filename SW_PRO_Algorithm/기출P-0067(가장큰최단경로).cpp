#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
#include <string.h>
using namespace std;

// �÷��̵����

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

		vector<int> del(n);					// ������ ���� ����
		vector<bool> check(n + 1, false);	// ��� ���� ����
		
		for (int i = 0; i < n; ++i) {
			cin >> del[i];
			info[i + 1][i + 1] = 0;
		}

		for (int i = 1; i <= n-1; ++i) {	// ���� ���� ����
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
		
		for (int y = n - 1; y >= 0; --y) {		// ����
			int i = del[y];
			check[i] = true;
			long long big = 0;
			for (int j = 1; j <= n; ++j) {	// ������
				if (info[j][i] == -1)		//  ����-���� ���±��� ������
					continue;
				for (int k = 1; k <= n; ++k) { 	// ������
					if (info[i][k] == -1 || j == k)			// ����-���� ���±��� ���ų� ����=�����̸�
						continue;
					
					if (info[j][k] == -1 || info[j][k] > info[j][i] + info[i][k])  		// ����-���� ���� ���ų� �����ϴ� �ͺ��� Ŭ��
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