#include <iostream>
#include <vector>
using namespace std;

int getIndex(int n) {			// �迭ũ�� ���ϱ�
	int temp = 1;
	while (temp < n)
		temp = temp << 1;
	return temp * 2;
}

int P_0019() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n, q;
		cin >> n >> q;
		long long ans = 0;

		int size = getIndex(n);
		int start = size - n - 1;
		vector <long long> v(size, 0);
		int num = 1;
		for (int i = size-n; i < size; ++i)
			v[i] = num++;

		int p = (size-1) / 2;				// ������ ���ϱ�
		for (int i = p; i > 0; --i) 
			v[i] = v[i * 2] + v[i * 2 + 1];


		for(int k =0; k<q; ++k){
			int a, x, y;
			cin >> a >> x >> y;

			if (a) {		// �ձ��ϱ�
				int L = x + start;
				int R = y + start;
				long long S = 0;

				while (L <= R) {
					if (L % 2 == 1) {		// ���� ���� ������ �ڽ��϶�
						S += v[L];			// ���� ���� �����ϰ�
						++L;				// �ε��� ����
						if (L == R) {		// ������ �Դٸ�
							S += v[L];		
							break;			// ����
						}
						else				// ���� �ڽ��� �Ǿ����ϱ�
							L /= 2;			// �θ�� ����
					}	
					else 					// ���� ���� ���� �ڽ��϶�
						L /= 2;				// �θ�� ����

					if (R % 2 == 1) 		// ������ ���� ������ �ڽ��϶�
						R /= 2;				// �θ�� ����
					else { 					// ������ ���� ���� �ڽ��϶�
						S += v[R];			// ���簪�� ����
						--R;				// �ε��� ��������
						R /= 2;				// ������ �ڽ��̴ϱ� �θ�� ����
					}
				}
				ans += S;
				ans %= 1000000007;
			}else{			// ����
				int target = x + start;
				int pos = target;
				long long gap = y - v[target];
				v[target] = y;
				pos >>= 1;			// �θ�� �̵�
				while (pos > 0) {	// ��Ʈ�� �ƴ϶�� ��� ����
					v[pos] += gap;
					pos >>= 1;
				}
			}
		}
		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}