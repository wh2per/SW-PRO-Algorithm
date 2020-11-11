#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T = 0;
	cin >> T;

	int ans[11];

	for (int i = 0; i < T; i++) {

		memset(ans, 0, sizeof(ans));

		int cnt = 0;
		cin >> cnt;

		string input;
		getline(cin, input);
		string cmd;
		int X = 0;

		for (int j = 0; j < cnt; j++) {

			getline(cin, input);
			stringstream ssCmd(input);

			ssCmd >> cmd;
			if (cmd == "add") {
				if (ssCmd >> X) {
					ans[1] = ans[1] + X;
				}
				else {
					ans[1] = ans[1] + ans[2];
				}
			}
			else if (cmd == "mul") {
				if (ssCmd >> X) {
					ans[1] = ans[1] * X;
				}
				else {
					ans[1] = ans[1] * ans[2];
				}
			}
			else if (cmd == "rotate") {
				int D = 0;
				int C = 0;
				ssCmd >> D;
				ssCmd >> C;

				int tmp[11];
				for (int k = 1; k <= 10; k++) {
					tmp[k] = ans[k];
				}

				if (D == 1) {
					for (int k = 1; k <= 10; k++) {
						if (k + C > 10) {
							ans[(k + C) % 10] = tmp[k];
						}
						else {
							ans[k + C] = tmp[k];
						}
					}
				}
				else if (D == 0) {
					for (int k = 1; k <= 10; k++) {
						if (k - C < 1) {
							ans[k - C + 10] = tmp[k];
						}
						else {
							ans[k - C] = tmp[k];
						}
					}
				}
			}
		}

		cout << "#" << (i + 1);
		for (int i = 1; i <= 10; i++) {
			cout << " " << ans[i];
		}
		cout << '\n';
	}

	return 0;
}