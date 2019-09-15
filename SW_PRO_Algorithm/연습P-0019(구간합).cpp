#include <iostream>
#include <vector>
using namespace std;

int getindex(int n) {			// 배열크기 정하기
	int temp = 1;
	while (temp < n)
		temp = temp << 1;
	return temp * 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, q;
		cin >> n >> q;
		long long ans = 0;

		int size = getindex(n);
		int start = size - n - 1;
		vector <long long> v(size, 0);
		int num = 1;
		for (int i = size-n; i < size; ++i)
			v[i] = num++;

		int p = (size-1) / 2;				// 구간합 구하기
		for (int i = p; i > 0; --i) 
			v[i] = v[i * 2] + v[i * 2 + 1];


		for(int k =0; k<q; ++k){
			int a, x, y;
			cin >> a >> x >> y;

			if (a) {		// 합구하기
				int L = x + start;
				int R = y + start;
				long long S = 0;

				while (L <= R) {
					if (L % 2 == 1) {		// 왼쪽 끝이 오른쪽 자식일때
						S += v[L];			// 현재 값만 저장하고
						++L;				// 인덱스 증가
						if (L == R) {		// 끝까지 왔다면
							S += v[L];		
							break;			// 종료
						}
						else				// 왼쪽 자식이 되었으니까
							L /= 2;			// 부모로 가기
					}	
					else 					// 왼쪽 끝이 왼쪽 자식일때
						L /= 2;				// 부모로 가기

					if (R % 2 == 1) 		// 오른쪽 끝이 오른쪽 자식일때
						R /= 2;				// 부모로 가기
					else { 					// 오른쪽 끝이 왼쪽 자식일때
						S += v[R];			// 현재값만 저장
						--R;				// 인덱스 왼쪽으로
						R /= 2;				// 오른쪽 자식이니까 부모로 가기
					}
				}
				ans += S;
				ans %= 1000000007;
			}else{			// 변경
				int target = x + start;
				int pos = target;
				long long gap = y - v[target];
				v[target] = y;
				pos >>= 1;			// 부모로 이동
				while (pos > 0) {	// 루트가 아니라면 계속 진행
					v[pos] += gap;
					pos >>= 1;
				}
			}
		}
		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}