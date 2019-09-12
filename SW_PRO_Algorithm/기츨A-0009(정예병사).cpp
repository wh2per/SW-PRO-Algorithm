#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp_sol(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.first < p2.first)
		return true;
	else
		return false;
}

int A_0009() {
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; ++t) {
		int answer = 1;
		
		vector<pair<int, int>> v;
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			int at, df;
			scanf("%d %d",&at,&df);
			v.push_back({at,df});
		}

		sort(v.begin(), v.end(), cmp_sol);
		
		int dmin = v[0].second;
		for (int i = 1; i < n; ++i) {
			if (dmin > v[i].second) {
				dmin = v[i].second;
				++answer;
			}
		}

		printf("#%d %d\n",t,answer);
	}
	return 0;
}