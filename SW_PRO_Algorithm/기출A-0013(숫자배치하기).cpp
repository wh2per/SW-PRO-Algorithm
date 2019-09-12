#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[11][11];

int A_0013() {
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; ++t) {
		int answer = 0;
		
		int n;
		scanf("%d", &n);
		vector<int> temp;
		for (int i = 0; i < n; ++i)
			temp.push_back(i);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				scanf("%d", &board[i][j]);
		}

		do {
			int tans = 0;
			for (int k = 0; k < n; ++k) 
				tans += board[k][temp[k]];
			if (tans > answer)
				answer = tans;
		} while (next_permutation(temp.begin(), temp.end()));

		printf("#%d %d\n", t, answer);
	}
	return 0;
}