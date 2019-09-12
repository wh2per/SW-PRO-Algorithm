#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int Q;
int V[1310742 * 2];		// 1 ~ 100,000 �߿��� ���� ���ڸ� �� �� ���� ����
string RESULT;

void update(int id, bool isAdd) {	// ���ڸ� ���� �� +1, ���ڰ� ��÷�Ǿ��� �� -1
	while (id > 0) {
		V[id] += isAdd ? 1 : -1;
		id >>= 1;
	}
}

void query(int n) {
	int id = 1;						// ��Ʈ ��忡�� Ž�� ����
	while (id < 1310742) {
		if (V[id * 2] < n) {		// ���� �ڽ��� ���� ������ ã������ �������� ���� ��
			n -= V[id * 2];			// n���� ���� �ڽ��� ���� ������ŭ ���� ������ �ڽ����� �̵�
			id = id * 2 + 1;
		}
		else {						// ���� �ڽ��� ���� �������� ã������ ������ ���ų� ���� ��
			id = id * 2;			// ���� �ڽ����� �̵�
		}
	}
	RESULT.append(to_string(id - 1310742 + 1));
	RESULT.append(" ");						// V �迭������ �ε����� ���ڷ� ��ȯ
	update(id, false);						// ��÷�� ���� ���� ����
}

int P_0041() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		fill_n(V, 1310742 * 2, 0);
		RESULT = "";

		cin >> Q;
		for (int i = 0; i < Q; ++i) {
			int be, x;
			cin >> be >> x;
			if (be == 1) 		// �����ڰ� ī�带 �̴´�.
				update(x - 1 + 1310742, true);

			else 				// �����ڰ� ī�带 �̴´�.
				query(x);
		}
		cout << "#" << t << " " << RESULT << "\n";
	}

	return 0;
}