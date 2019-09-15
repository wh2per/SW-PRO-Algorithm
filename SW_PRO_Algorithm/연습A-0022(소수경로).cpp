#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 에라토스테네스의 체 - check이 false이면 소수
	vector<int> p(10000);
	vector<bool> pnum(10000);
	int pn = 0;
	pnum[0] = pnum[1] = true;
	for (int i = 2; i*i <= 9999; i++) {
		if (pnum[i] == false) {
			p[pn++] = i;
			for (int j = i + i; j <= 9999; j += i)
				pnum[j] = true;
		}
	}

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		string a, b;
		cin >> a >> b;
		cout << "#" << t << " ";

		queue<pair<string, int>> q;
		vector<bool> check(10000, false);
		q.push({a,0});
		check[stoi(a)] = true;

		while (!q.empty()) {
			string curr = q.front().first;
			int count = q.front().second;
			q.pop();

			if (curr == b) {
				cout << count << "\n";
				break;
			}

			for (int i = 0; i < 4; ++i) {
				string next = curr;
				for (int j = 0; j < 10; ++j) {
					if (i == 0 && j == 0)
						continue;
					next[i] = j+'0';
					int temp = stoi(next);
					if (!check[temp] && !pnum[temp]) {
						q.push({ next,count + 1 });
						check[temp] = true;
					}
				}
			}
		}
	}

	return 0;
}