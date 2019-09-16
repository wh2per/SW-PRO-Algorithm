#include<iostream>
using namespace std;

int v[100001];

int find(int n)
{
	if (v[n] == n)
		return n;
	v[n] = find(v[n]);
	return v[n];
}

void merge(int a, int b) {
	int num1, num2;
	num1 = find(a);
	num2 = find(b);
	if (num1 == num2)
		return;
	v[num2] = num1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, m,ans=0;
		cin >> n >> m;

		for (int i = 1; i <= n; ++i)		// 현재 자신의 수로 초기화
			v[i] = i;

		for (int i = 0; i < m; ++i) {
			int a, x, y;
			cin >> a >> x >> y;
			if (a == 0) {		// 합집합
				merge(x, y);
			}
			else {			// 검사
				if (find(x) == find(y))
					++ans;
			}
		}

		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}