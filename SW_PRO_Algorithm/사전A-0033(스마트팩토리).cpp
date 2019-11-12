#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int factory[5001][5];
char engineer[5];
int dp[5001][1<<5][27];			// curr state engineer
int n, m, k;

int bitmask_dp(int curr, int state, char eng) {
	if (curr == n)
		return 0;

	int& ret = dp[curr][state][eng-'A'+1];
	if (ret != -1)
		return ret;

	for (int i = 0; i < k; ++i) {
		if (((state & (1 << i)) == 0)) { 			// 아직 선택 안한 엔지니어이면서 만질수있는 부품의 갯수가 0개가 아닐때
			int sub = bitmask_dp(curr + 1, state | 1 << i, engineer[i]);
			if (sub != -1)
				ret = max(ret, sub + factory[curr][i]);
		}
		else if (engineer[i] == eng) {
			int sub = bitmask_dp(curr + 1, state, engineer[i]);
			if (sub != -1)
				ret = max(ret, sub + factory[curr][i]);
		}
		
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input2.txt", "r", stdin);

	int test;
	cin >> test;

	for (int t = 1; t <= test; ++t) {
		cin >> n >> m >> k;

		memset(dp, -1, sizeof(dp));
		memset(factory, 0, sizeof(factory));

		for (int i = 0; i < k; ++i) {				// 엔지니어 입력
			char c;
			cin >> c;
			engineer[i] = c;					// 각 엔지니어가 어떤 부품을 만들수 있는지 저장
		}

		for (int i = 0; i < m; ++i) {				// 공장 라인 세팅
			for (int j = 0; j < n; ++j) {
				char c;
				cin >> c;
				for (int e = 0; e < k; ++e) {
					if (engineer[e] == c)
						++factory[j][e];
				}
			}
		}

		cout << "#" << t << " " << bitmask_dp(0,0,'A'-1) << "\n";
	}
		return 0;
}
