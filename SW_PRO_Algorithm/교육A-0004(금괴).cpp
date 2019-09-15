#include <iostream>
using namespace std;

int gcd(int a, int b) {		// 최대공약수
	if (a%b == 0)
		return b;
	else
		return gcd(b, a%b);
}

int lcm(int a, int b) {		// 최소공배수
	return a*b / gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int n, m, ans = 0;
		cin >> n >> m;

		if (n > m && n%m != 0)			// 금괴가 더 많을 경우 사람보다 작게 만들자
			n %= m;

		int g = gcd(n, m);

		if (g != 1) { // 서로소가 아닐떄
			int l = lcm(n, m);
			if (m%n == 0)
				cout << "#" << t << " " << l - g << "\n";
			else {
				n /= g;
				m /= g;
				cout << "#" << t << " " << g * (m - 1) << "\n";
			}
		}
		else		// 두 수가 서로소이면
			cout << "#" << t << " " << m - 1 << "\n";
	}
	return 0;
}