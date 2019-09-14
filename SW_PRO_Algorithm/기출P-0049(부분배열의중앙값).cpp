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
			if (maxNum < num) // k = 1�� ���� ���� �ִ� ����
				maxNum = num;
		}

		if (k == 1)
			ans = maxNum; // // ���� ũ�Ⱑ 1�� �� �迭�� �ִ� ���
		else {
			sort(data.begin(), data.end(), cmp_data); // �������� ����

			for (int i = 0; i < n; ++i) // �� �迭�� �ε����� ���ĵ� �迭�� �ε����� ��ȯ�Ͽ� �ε��� Ʈ�� ���ٿ� ���
				sortedIndex[data[i].first] = i;
			size = getindex(n);
			tree.assign(size * 2, 0);

			/* �� �迭�� ������ ���ĵ� �迭�� �ε����� ��ȯ�Ͽ� �ش� �ε����� 1�� �Է�
			�ε��� Ʈ�� Build ��
			��Ʈ ��忡�� ���� ũ�Ⱑ �Էµǰ�, K / 2 + 1��° ���ڰ� �ִ� ���� ��带 Ž��
			�ش� ���� ���� ���ĵ� �迭�� �ε����̰�, �� �迭�� �ε����� ��ȯ�Ͽ� �߾Ӱ� ����
			*/

			for (int i = 0; i < k - 1; i++) // ���� üũ�� ���� 0 �ε������� K - 1 ���� 1�� ǥ��
				addOne(sortedIndex[i], 1, size);

			for (int i = m; i < n - m; i++) { // ��� ������ ���ؼ�
				if (i != m)
					addOne(sortedIndex[i - m - 1], -1, size); // ���� ������ ù �ε��� -1, ���� ������ ������ �ε��� +1
				addOne(sortedIndex[i + m], 1, size);
				int id = 1;
				int median = m + 1;

				while (id < size) { // �߾Ӱ� ��ġ Ž�� (������� ���ĵ� �迭�� �ε���)
					if (tree[(id << 1)] < median) {
						median -= tree[id << 1];
						id = id * 2 + 1;
					}
					else
						id = id * 2;
				}
				ans = max(ans, data[id - size].second); // ���ĵ� �迭�� �ε����� �� �迭 �߾Ӱ��� �ִ� ���� 
			}
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}