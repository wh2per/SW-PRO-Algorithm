#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int Q;
int V[1310742 * 2];		// 1 ~ 100,000 중에서 나올 숫자를 알 수 없기 때문
string RESULT;

void update(int id, bool isAdd) {	// 숫자를 뽑을 때 +1, 숫자가 당첨되었을 때 -1
	while (id > 0) {
		V[id] += isAdd ? 1 : -1;
		id >>= 1;
	}
}

void query(int n) {
	int id = 1;						// 루트 노드에서 탐색 시작
	while (id < 1310742) {
		if (V[id * 2] < n) {		// 왼쪽 자식의 숫자 개수가 찾으려는 순위보다 작을 때
			n -= V[id * 2];			// n에서 왼쪽 자식의 숫자 개수만큼 빼고 오른쪽 자식으로 이동
			id = id * 2 + 1;
		}
		else {						// 왼쪽 자식의 숫자 개수보다 찾으려는 순위가 같거나 작을 때
			id = id * 2;			// 왼쪽 자식으로 이동
		}
	}
	RESULT.append(to_string(id - 1310742 + 1));
	RESULT.append(" ");						// V 배열에서의 인덱스를 숫자로 변환
	update(id, false);						// 당첨된 숫자 개수 감소
}

int main() {
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
			if (be == 1) 		// 참가자가 카드를 뽑는다.
				update(x - 1 + 1310742, true);

			else 				// 진행자가 카드를 뽑는다.
				query(x);
		}
		cout << "#" << t << " " << RESULT << "\n";
	}

	return 0;
}