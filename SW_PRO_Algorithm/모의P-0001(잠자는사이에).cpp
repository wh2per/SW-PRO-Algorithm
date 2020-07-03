#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

int parent[30001];
set<pair<int, int>> cycle;
int check[30001];
pair<int, int> info[30001];

bool find_cycle(int start, int end) {
	while (start != end && start != 0) {
		start = parent[start];
		if (start == end)
			return true;
	}
	return false;
}

void set_cycle(int start) {
	if (check[start] == 2)
		return;
	++check[start];

	if (check[start] == 2)
		cycle.insert({parent[start], start});

	set_cycle(parent[start]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int n;
		cin >> n;

		memset(parent, 0, sizeof(parent));
		memset(check, 0, sizeof(check));
		cycle.clear();
		int temp_son = 0;
		int temp_mom = 0;

		for (int i = 0; i < n; ++i) {
			int start, end;
			cin >> start >> end;

			info[i].first = start;
			info[i].second = end;

			if (parent[end] != 0) {
				temp_mom = parent[end];
				temp_son = end;
			}
			parent[end] = start;
		}

		if (temp_son == 0) {		// 모두 부모가 하나씩일 때 
			set_cycle(info[n-1].second);

			for (int i = n - 1; i >= 0; --i) {
				if (cycle.count(info[i]) > 0) {
					cout << "#" << t << " " << info[i].first << " " << info[i].second << "\n";
					break;
				}
			}
			continue;
		}

		if (find_cycle(temp_mom, temp_son))		// 삭제
			cout << "#" << t << " " << temp_mom << " " << temp_son << "\n";
		else
			cout << "#" << t << " " << parent[temp_son] << " " << temp_son << "\n";

	}

	return 0;
}
