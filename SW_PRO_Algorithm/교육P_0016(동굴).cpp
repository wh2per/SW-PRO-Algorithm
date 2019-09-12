#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int P_0016() {
	int tc;
	scanf("%d",&tc);

	for (int t = 1; t <= tc; ++t) {
		int n, h;
		scanf("%d %d",&n,&h);

		vector<int> cave1(h + 1, 0);		// ��������
		vector<int> cave2(h + 1, 0);		// ������
		for (int i = 0; i < n; ++i) {
			int th;
			scanf("%d", &th);

			if (i % 2 == 1) 		// ����
				++cave2[h-th+1];
			else					// ������
				++cave1[th];
		}

		for (int i = h; i > 0; --i)
			cave1[i - 1] += cave1[i];
		for (int i = 1; i < h; ++i)
			cave2[i + 1] += cave2[i];

		int minB = n + 1;
		int minC = 0;

		for (int i = 1; i <= h; ++i) {
			int count = cave1[i] + cave2[i];
			if (minB > count) {
				minB = count;
				minC = 1;
			}
			else if (minB == count)
				++minC;
		}

		printf("#%d %d %d\n",t,minB, minC);
	}
	return 0;
}