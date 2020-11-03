#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
using namespace std;

int factor[201][201];
int mom[201];
int son[201];

string convertInt(int number) {
	stringstream ss;
	ss << number;
	return ss.str();
}

string multi_string(string a, int i) {
	string ans = "";

	int ai = a.length() - 1;

	int over = 0;
	while (ai != -1) {
		int c = a[ai] - '0';

		int prev_over = over;
		over = (c * i + prev_over) / 10;

		ans = convertInt((c * i + prev_over) % 10) + ans;
		--ai;
	}

	if (over != 0)
		ans = convertInt(over) + ans;

	return ans;
}

int main() {
	// �Ҽ� �������
	for (int i = 2; i < 201; ++i) {
		int num = i;
		while (num != 1) {
			for (int j = 2; j <= i; ++j) {
				if (num % j == 0) {
					++factor[i][j];
					num /= j;
					break;
				}
			}
		}
	}

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		memset(mom, 0, sizeof(mom));
		memset(son, 0, sizeof(son));
		int n, m, k;
		cin >> n >> m >> k;

		// ���ս� n-mCk-1 * mCm-k+1 /  nCm

		// ���ڿ� ���� �Ҽ� ���
		for (int i = n - m; i > n - m - k + 1; --i) {
			for (int j = 2; j < 201; ++j)
				son[j] += factor[i][j];
		}

		for (int i = m; i > k - 1; --i) {
			for (int j = 2; j < 201; ++j)
				son[j] += factor[i][j];
		}

		for (int i = k - 1; i > 1; --i) {
			for (int j = 2; j < 201; ++j)
				son[j] -= factor[i][j];
		}

		for (int i = m - k + 1; i > 1; --i) {
			for (int j = 2; j < 201; ++j)
				son[j] -= factor[i][j];
		}

		// �и� ���� �Ҽ� ���
		for (int i = n; i > n - m; --i) {
			for (int j = 2; j < 201; ++j)
				mom[j] += factor[i][j];
		}

		for (int i = m; i > 1; --i) {
			for (int j = 2; j < 201; ++j)
				mom[j] -= factor[i][j];
		}

		// ���ڿ� �и� ��ġ�� �Ҽ��� ������ -> ��� ����
		for (int i = 2; i < 201; ++i) {
			if (son[i] != 0 && mom[i] != 0) {		// ���ڿ� �и� �Ѵ� ���� ���� ���
				if (son[i] >= mom[i]) {		// ���� ���� �� Ŭ ��
					son[i] -= mom[i];
					mom[i] = 0;
				}
				else {		// �и� ���� �� Ŭ ��
					mom[i] -= son[i];
					son[i] = 0;
				}
			}
		}

		string mom_ans = "1";
		string son_ans = "1";

		for (int i = 2; i < 201; ++i) {
			for (int j = 0; j < mom[i]; ++j)
				mom_ans = multi_string(mom_ans, i);
		}

		for (int i = 2; i < 201; ++i) {
			for (int j = 0; j < son[i]; ++j)
				son_ans = multi_string(son_ans, i);
		}

		cout << "#" << t << " " << son_ans << "/" << mom_ans << "\n";
	}
	return 0;
}