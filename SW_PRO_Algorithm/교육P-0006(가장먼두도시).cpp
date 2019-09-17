#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

//�÷��̵� �ͼ�

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int n;
		cin >> n;

		vector<vector<int>> info(n, vector<int>(n,INT_MAX));

		for (int i = 0; i < n; ++i) {		// ���� ���
			for (int j = 0; j < n; ++j) 
				cin >> info[i][j];
		}

		int ans = 0;

		for (int i = 0; i < n; ++i) {		
			for (int j = 0; j < n; ++j) {	// ������
				for (int k = 0; k < n; ++k) { 	// ������
					info[j][k] = min(info[j][k], info[j][i] + info[i][k]);
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {	// ������
				if (ans < info[i][j])
					ans = info[i][j];
			}
		}
		cout << "#" << t << " " << ans <<"\n";
	}
	return 0;
}