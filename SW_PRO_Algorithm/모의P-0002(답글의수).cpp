#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

int parent[50001];
set<int> info[50001];
int ans;
int index;

void count_reply(int x) {
	for (auto a : info[x]) {
		++ans;
		count_reply(a);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int tc;
	cin >> tc;


	for (int t = 1; t <= tc; ++t) {
		int m,a,x;
		ans = 0;
		index = 0;
		for (int i = 0; i < 50001; ++i) {
			parent[i] = i;
			info[i].clear();
		}

		cin >> m;

		while (m--) {
			cin >> a >> x;

			if (a == 1) {		// �� �߰�
				++index;
				
				if (x != 0) { 		// ��� �߰�	
					parent[index] = x;			// �θ� ���� 
					info[x].insert(index);	// �ڽ� ���� 
				}
			}
			else if (a == 2) {		// ��ۻ���
				info[parent[x]].erase(x);
			}
			else {		// ��� ī��Ʈ
				count_reply(x);
			}
		}
		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}
