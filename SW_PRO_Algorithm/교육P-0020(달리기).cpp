#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> runner;
vector<int> sorted_runner;
long long runner_count;

void merge(int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end) {
		if (runner[i] >= runner[j]) {
			sorted_runner[k] = runner[i];
			++i;
		}
		else {
			sorted_runner[k] = runner[j];
			runner_count += j - k;
			++j;
		}
		++k;
	}

	if (i > mid) {
		for (int t = j; t <= end; t++) {
			sorted_runner[k] = runner[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sorted_runner[k] = runner[t];
			k++;
		}
	}

	// 정렬된 배열을 삽입
	for (int t = start; t <= end; t++) {
		runner[t] = sorted_runner[t];
	}
}

void merge_sort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(start, mid);		// 좌측 정렬
		merge_sort(mid + 1, end);	// 우측 정렬
		merge(start, mid, end);
	}
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
		runner_count = 0;
		runner.assign(n, 0);
		sorted_runner.assign(n, 0);
		for (int i = 0; i < n; ++i)
			cin >> runner[i];

		int count = 0;
		
		merge_sort(0, n - 1);
		//for (auto a : sorted_runner)
		//	cout << a;
		//cout << endl;
		cout << "#" << t << " "<<runner_count<<"\n";
	}
	return 0;
}