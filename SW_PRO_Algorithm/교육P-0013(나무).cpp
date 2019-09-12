#include <iostream>
#include <algorithm>
using namespace std;

int P_0013() {
	int tc;
	scanf("%d",&tc);

	for (int t = 1; t <= tc; ++t) {
		int n, m;
		scanf("%d %d", &n, &m);

		int dmin = 99999999;
		int mli, mri;
		for (int i = 0; i < m; ++i) {
			int li, ri;
			scanf("%d %d", &li, &ri);
			if (dmin > ri - li) {
				mli = li;
				mri = ri;
				dmin = ri - li;
			}
		}
		
		printf("#%d\n%d\n",t,dmin+1);
		for (int i=1; i<=n; ++i)
			printf("%d ",i%(dmin+1));
		printf("\n");
	}

	return 0;
}