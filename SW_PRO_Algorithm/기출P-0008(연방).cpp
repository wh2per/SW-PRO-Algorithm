#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

// ���Ͽ� ���ε� - �Ųٷ��ϱ�

vector<pair<int,int>> info;		// ������������
vector<bool> check;
vector<vector<int>> query;		// ��������
vector<int> v;

int find(int n) {
	if (v[n] == n)
		return n;
	return v[n] = find(v[n]);
}

void merge(int a, int b) {
	int num1 = find(a);
	int num2 = find(b);
	if (num1 == num2)
		return;
	v[num2] = num1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, m;
		cin >> n >> m;
		
		info.assign(m+1, pair<int, int>());
		check.assign(m + 1, false);
		v.assign(n + 1, 0);

		for (int i = 1; i <= n; ++i)		// v �ʱ�ȭ
			v[i] = i;

		for (int i = 1; i <= m; ++i) {		// �������� ����
			int a, b;
			cin >> a >> b;
			info[i] = {a,b};				// ���° �������� ����
		}

		int q;
		cin >> q;
		query.clear();

		for (int i = 0; i < q; ++i) {		// ���� �ޱ�
			vector<int> qq;
			int a, b, c;
			cin >> a;
			
			qq.push_back(a);
			if (a == 1) {		// ���� ����
				cin >> b;
				qq.push_back(b);
				check[b] = true;		// �ʱ� �׷��� ���� �� ������ ����
			}
			else {		// ����
				cin >> b >> c;
				qq.push_back(b);
				qq.push_back(c);
			}
			query.push_back(qq);
		}

		for (int i = 1; i <= m; ++i) {		// �ڿ������� ������ �׷��� �����
			if (!check[i]) 					// ����� �� �ִ� ����
				merge(info[i].first,info[i].second);
		}

		stack<int> st;
		for (int i = q - 1; i >= 0; --i) {		// ������ �ڿ������� ����
			if (query[i][0] == 2) {		// ����
				if (find(query[i][1]) == find(query[i][2]))
					st.push(1);
				else
					st.push(0);
			}
			else {					// ���Ͽ�
				int k = query[i][1];
				merge(info[k].first, info[k].second);
			}
		}
		cout << "#" << t << " ";
		while (!st.empty()) {
			cout << st.top();
			st.pop();
		}
		cout << "\n";
	}

	return 0;
}