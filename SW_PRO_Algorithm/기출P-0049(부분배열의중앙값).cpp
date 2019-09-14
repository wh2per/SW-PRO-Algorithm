#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree;

int getindex(int n) {
	int temp = 1;
	while (temp < n)
		temp <<= 1;
	return temp;
}

bool cmp_data(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second < p2.second)
		return true;
	else
		return false;
}

void addOne(int id, int num, int s) {
	id += s;
	while (id > 0) {
		tree[id] += num;
		id >>= 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, k, m, d, size, maxNum = 0, ans = 0;

		cin >> n >> k;
		m = k / 2;

		vector<int> sortedIndex(n);
		vector<pair<int, int>> data(n);

		for (int i = 0; i < n; ++i) {
			int num;
			cin >> num;

			data[i] = { i,num };
			if (maxNum < num) // k = 1일 때를 위해 최댓값 저장
				maxNum = num;
		}

		if (k == 1)
			ans = maxNum; // // 구간 크기가 1일 때 배열의 최댓값 출력
		else {
			sort(data.begin(), data.end(), cmp_data); // 오름차순 정렬

			for (int i = 0; i < n; ++i) // 원 배열의 인덱스를 정렬된 배열의 인덱스로 변환하여 인덱스 트리 접근에 사용
				sortedIndex[data[i].first] = i;
			size = getindex(n);
			tree.assign(size * 2, 0);

			/* 원 배열의 구간을 정렬된 배열의 인덱스로 변환하여 해당 인덱스에 1을 입력
			인덱스 트리 Build 시
			루트 노드에는 구간 크기가 입력되고, K / 2 + 1번째 숫자가 있는 리프 노드를 탐색
			해당 리프 노드는 정렬된 배열의 인덱스이고, 원 배열의 인덱스로 변환하여 중앙값 도출
			*/

			for (int i = 0; i < k - 1; i++) // 구간 체크를 위해 0 인덱스부터 K - 1 개를 1로 표시
				addOne(sortedIndex[i], 1, size);

			for (int i = m; i < n - m; i++) { // 모든 구간에 대해서
				if (i != m)
					addOne(sortedIndex[i - m - 1], -1, size); // 이전 구간의 첫 인덱스 -1, 현재 구간의 마지막 인덱스 +1
				addOne(sortedIndex[i + m], 1, size);
				int id = 1;
				int median = m + 1;

				while (id < size) { // 중앙값 위치 탐색 (결과값은 정렬된 배열의 인덱스)
					if (tree[(id << 1)] < median) {
						median -= tree[id << 1];
						id = id * 2 + 1;
					}
					else
						id = id * 2;
				}
				ans = max(ans, data[id - size].second); // 정렬된 배열의 인덱스로 원 배열 중앙값의 최댓값 갱신 
			}
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}