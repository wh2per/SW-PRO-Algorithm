#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int arr[1000001];
int cnt[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("sample_input.txt", "r", stdin);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int n, k;
		cin >> n >> k;

		memset(arr, 0, sizeof(arr));
		memset(cnt, 0, sizeof(cnt));

		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		int start = 0;
		int len = 0;		// üũ�� �ܾ� ����
		int word = 0;		// ���� �ܾ� ����
		int ans = 1000001;

		for (int i = 0; i < n; ++i) {
			++cnt[arr[i]];
			++len;
			if (cnt[arr[i]] == 1) {		// ó�� ���� �ܾ���
				++word;
				while (word == k) {		// ���� �ܾ k�� �Ǿ����� -> �տ������� �ϳ��� ��������
					--cnt[arr[start]];

					if (cnt[arr[start]] == 0) {		// �ش� �ܾ ������ ���
						ans = min(ans, len);
						--word;
						++start;
						--len;
						break;
					}
					++start;
					--len;
					ans = min(ans, len);
				}
			}
		}

		if (ans == 1000001)
			cout << "#" << t << " -1\n";
		else
			cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}