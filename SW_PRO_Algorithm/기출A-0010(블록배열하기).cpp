#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A_0010() {
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; ++t) {
		int answer = 0;
		int n, k;
		scanf("%d %d", &n, &k);
		
		vector<vector<int>> v(k, vector<int>(1,0));
		vector<int> temp;
		for (int i = 0; i < n; ++i) {
			int score;
			scanf("%d",&score);
			temp.push_back(score);
		}

		for (int i = 0; i < n; ++i) {
			int order;
			scanf("%d", &order);
			v[order-1].push_back(temp[i]);
		}

		for (int i = 0; i < k; ++i)
			sort(v[i].begin(), v[i].end());
		
		for (int i = k - 1; i >= 0; --i) {
			int ts = i;			// 어디층이 가장 높았는지 기억용
			int smax = 0;		// 0으로 초기화

			for (int j = i; j < k; ++j) {
				if (v[j].back() > smax) {
					smax = v[j].back();
					ts = j;
				}
			}
			answer += smax;
			v[ts].pop_back();
		}

		printf("#%d %d\n", t, answer);
	}
	return 0;
}