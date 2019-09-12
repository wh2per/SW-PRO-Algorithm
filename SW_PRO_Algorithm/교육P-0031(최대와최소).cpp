#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getindex(int n) {			// 배열크기 정하기
	int temp = 1;
	while (temp < n)
		temp = temp << 1;
	return temp * 2;
}

int P_0031() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, q;
		cin >> n >> q;
		int ans_min = 0;
		int ans_max = 0;

		int size = getindex(n);
		int start = size - n - 1;
		vector <int> v1(size, 0);
		vector <int> v2(size, 0);
		for (int i = size - n; i < size; ++i) {
			int num;
			cin >> num;
			v1[i] = v2[i] = num;
		}

		int p = (size - 1) / 2;				// 구간합 구하기
		for (int i = p; i > 0; --i) {
			v1[i] = min(v1[i * 2], v1[i * 2 + 1]);
			v2[i] = max(v2[i * 2], v2[i * 2 + 1]);
		}

		for (int k = 0; k<q; ++k) {
			int a, x, y;
			cin >> a >> x >> y;

			if (a == 0) {		// 구간 대표값 구하기
				// 최소값 구하기
				int l = x + start;
				int r = y + start;
				int ans = 999999;
				while (l <= r) {
					ans = min(ans, min(v1[l], v1[r]));
					l = (l + 1) >> 1;
					r = (r - 1) >> 1;
				}
				ans_min += ans;

				// 최대값 구하기
				l = x + start;
				r = y + start;
				ans = -1;
				while (l <= r) {
					ans = max(ans, max(v2[l], v2[r]));
					l = (l+1) >> 1;
					r = (r-1) >> 1;
				}
				ans_max += ans;
			}
			else {			// 변경
				int target = x + start;
				int pos = target;
				v1[target] = y;
				int prev = pos;
				pos >>= 1;			// 부모로 이동
				while (pos > 0) {	// 루트가 아니라면 계속 진행
					if(prev%2==1)
						v1[pos] = min(v1[prev], v1[prev-1]);
					else
						v1[pos] = min(v1[prev], v1[prev+1]);
					prev = pos;
					pos >>= 1;
				}

				target = x + start;
				pos = target;
				v2[target] = y;
				prev = pos;
				pos >>= 1;			// 부모로 이동
				while (pos > 0) {	// 루트가 아니라면 계속 진행
					if (prev % 2 == 1)
						v2[pos] = max(v2[prev], v2[prev - 1]);
					else
						v2[pos] = max(v2[prev], v2[prev + 1]);
					prev = pos;
					pos >>= 1;
				}
			}
		}
		cout << "#" << t << " " << ans_max << " "<<ans_min<< "\n";
	}

	return 0;
}