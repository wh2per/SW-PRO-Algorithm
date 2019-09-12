#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> hanoi_stack;
const char hanoi_top[] = { 'A','B','C' };
int hanoi_count;

void hanoi(int n, int from, int by, int to) {
	if(n == 1) {
		vector<int> v;
		v.push_back(n);
		v.push_back(from);
		v.push_back(to);
		hanoi_stack.push_back(v);
		return;
	}

	hanoi(n - 1, from, to, by);		// n-1�� ������ 1���� 3�� �̿��Ͽ� 2�� �ű��
	vector<int> v;
	v.push_back(n);
	v.push_back(from);
	v.push_back(to);
	hanoi_stack.push_back(v);
	hanoi(n - 1, by, from, to);		// n-1�� ������ 2���� 1�� �̿��Ͽ� 3���� �ű��.
}

int A_0003() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n;
		cin >> n;

		hanoi_stack.clear();
		hanoi(n, 1, 2, 3);
		cout << "#" << t << " " << hanoi_stack.size() << "\n";
		for (auto a : hanoi_stack) {
			cout << a[0] << " : " << hanoi_top[a[1] - 1] << " -> "<< hanoi_top[a[2] -1]<<"\n";
		}
	}

	return 0;
}