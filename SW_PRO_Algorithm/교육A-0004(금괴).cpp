#include <iostream>
using namespace std;

int gcd(int a, int b) {		// �ִ�����
	if (a%b == 0)
		return b;
	else
		return gcd(b, a%b);
}

int lcm(int a, int b) {		// �ּҰ����
	return a*b / gcd(a, b);
}

int A_0004() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int n, m, ans = 0;
		cin >> n >> m;

		if (n > m && n%m != 0)			// �ݱ��� �� ���� ��� ������� �۰� ������
			n %= m;

		int g = gcd(n, m);

		if (g != 1) { // ���μҰ� �ƴҋ�
			int l = lcm(n, m);
			if (m%n == 0)
				cout << "#" << t << " " << l - g << "\n";
			else {
				n /= g;
				m /= g;
				cout << "#" << t << " " << g * (m - 1) << "\n";
			}
		}
		else		// �� ���� ���μ��̸�
			cout << "#" << t << " " << m - 1 << "\n";
	}
	return 0;
}