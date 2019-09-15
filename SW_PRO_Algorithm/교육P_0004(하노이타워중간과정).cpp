#include <iostream>
#include <vector>
using namespace std;

vector<int> hanoi_arr;

bool hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		if (hanoi_arr[n - 1] == from || hanoi_arr[n - 1] == to)
			return true;
		else
			return false;
	}

	if (hanoi_arr[n - 1] == from)
		return hanoi(n - 1, from, to, by);
	else if (hanoi_arr[n - 1] == to)
		return hanoi(n - 1, by, from, to);
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int n;
		cin >> n;

		hanoi_arr.assign(n, 0);

		for (int i = 0; i < n; ++i)
			cin >> hanoi_arr[i];

		bool flag = false;
		flag = hanoi(n, 1, 3, 2);
		if (flag)
			cout << "#" << t << " " << "yes" << "\n";
		else
			cout << "#" << t << " " << "no" << "\n";
	}
	return 0;
}

