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

// 유니온 파인드 - 거꾸로하기

vector<pair<int,int>> info;		// 교류관계정보
vector<bool> check;
vector<vector<int>> query;		// 쿼리정보
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

		for (int i = 1; i <= n; ++i)		// v 초기화
			v[i] = i;

		for (int i = 1; i <= m; ++i) {		// 교류관계 정보
			int a, b;
			cin >> a >> b;
			info[i] = {a,b};				// 몇번째 교류인지 저장
		}

		int q;
		cin >> q;
		query.clear();

		for (int i = 0; i < q; ++i) {		// 쿼리 받기
			vector<int> qq;
			int a, b, c;
			cin >> a;
			
			qq.push_back(a);
			if (a == 1) {		// 교류 끊기
				cin >> b;
				qq.push_back(b);
				check[b] = true;		// 초기 그래프 형성 시 배제할 쿼리
			}
			else {		// 질문
				cin >> b >> c;
				qq.push_back(b);
				qq.push_back(c);
			}
			query.push_back(qq);
		}

		for (int i = 1; i <= m; ++i) {		// 뒤에서부터 시작할 그래프 만들기
			if (!check[i]) 					// 사용할 수 있는 쿼리
				merge(info[i].first,info[i].second);
		}

		stack<int> st;
		for (int i = q - 1; i >= 0; --i) {		// 쿼리를 뒤에서부터 진행
			if (query[i][0] == 2) {		// 질문
				if (find(query[i][1]) == find(query[i][2]))
					st.push(1);
				else
					st.push(0);
			}
			else {					// 유니온
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