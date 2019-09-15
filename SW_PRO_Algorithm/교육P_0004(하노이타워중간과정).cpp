#include <iostream>
#include <string>
using namespace std;

string hanoi_arr;
string hanoi_check;
int hanoi_n;
bool hanoi_flag;

void hanoi(int n, char from, char by, char to) {
	if (n == 1) {
		printf("%d %c\n", n, to);
		hanoi_arr[n - 1] = to;
		if (hanoi_arr == hanoi_check) {
			hanoi_flag = true;
		}
		return;
	}
	hanoi(n - 1, from, to, by);		// n-1�� ������ 1���� 3�� �̿��Ͽ� 2�� �ű�� 
	printf("%d %c\n",n, to);
	hanoi_arr[n - 1] = to;
	if (hanoi_arr == hanoi_check) {
		hanoi_flag = true;
		return;
	}
	hanoi(n - 1, by, from, to);		// n-1�� ������ 2���� 1�� �̿��Ͽ� 3���� �ű��. 
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		cin >> hanoi_n;

		hanoi_arr = "";
		hanoi_check = "";
		hanoi_flag = false;

		for (int i = 0; i < hanoi_n; ++i) {
			char c;
			cin >> c;
			hanoi_check += c;
			hanoi_arr += '1';
		}

		hanoi(hanoi_n,'1','3','2');
		if(hanoi_flag)
			cout << "#" << t << " " << "yes" << "\n";
		else
			cout << "#" << t << " " << "no" << "\n";
	}
	return 0;
}