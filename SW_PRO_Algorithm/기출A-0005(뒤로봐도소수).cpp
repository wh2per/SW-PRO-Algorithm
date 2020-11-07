#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

bool sosu[100001];

bool isPalin(int num) {
	string number = to_string(num);
	//string number;
	//stringstream ss;
	//ss << num;
	//number = ss.str();

	for (int j = 0; j < number.size() / 2; j++)
	{
		char s = number[j];
		char e = number[number.size() - 1 - j];
		if (s != e)
			return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	// 소수 모두저장
	sosu[1] = true;
	for (int i = 2; i * i <= 100000; i++) {
		if (sosu[i] == false) {
			for (int j = i * i; j <= 100000; j += i) {
				sosu[j] = true;
			}
		}
	}

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int a, b;
		cin >> a >> b;

		int ans = 0;
		for (int i = a; i <= b; ++i) {
			if (!sosu[i] && isPalin(i))		// 소수일 때 && 회문일때
				++ans;
		}

		cout << "#" << t << " " << ans << "\n";
	}


	return 0;
}