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
	// 소수 모두저장
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

		// 조합식 n-mCk-1 * mCm-k+1 /  nCm

		// 분자에 곱할 소수 계산
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

		// 분모에 곱할 소수 계산
		for (int i = n; i > n - m; --i) {
			for (int j = 2; j < 201; ++j)
				mom[j] += factor[i][j];
		}

		for (int i = m; i > 1; --i) {
			for (int j = 2; j < 201; ++j)
				mom[j] -= factor[i][j];
		}

		// 분자와 분모에 겹치는 소수는 빼주자 -> 약분 개념
		for (int i = 2; i < 201; ++i) {
			if (son[i] != 0 && mom[i] != 0) {		// 분자와 분모에 둘다 값이 있을 경우
				if (son[i] >= mom[i]) {		// 분자 값이 더 클 때
					son[i] -= mom[i];
					mom[i] = 0;
				}
				else {		// 분모 값이 더 클 때
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