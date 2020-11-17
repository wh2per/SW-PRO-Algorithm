#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int friends[101];
int check[101];
int team;
int prevTeam;
bool flag;

void dfs(int i) {
	check[i] = team;

	if (check[friends[i]] == 0)
		dfs(friends[i]);
	else if (check[friends[i]] < team) {
		flag = true;
		prevTeam = check[friends[i]];
		--team;
	}

	if (flag)
		check[i] = prevTeam;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("./sample_input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n;
		cin >> n;

		memset(friends, 0, sizeof(friends));
		memset(check, 0, sizeof(check));
		team = 1;

		for (int i = 1; i <= n; ++i)
			cin >> friends[i];

		for (int i = 1; i <= n; ++i) {
			if (check[i] == 0) {		// 한번도 확인하지 않은 아이
				++team;
				flag = false;
				prevTeam = 0;
				dfs(i);
			}
		}

		cout << "#" << t << " " << team - 1 << "\n";
	}


	return 0;
}