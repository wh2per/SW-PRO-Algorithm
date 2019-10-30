#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

int layer[12];
unsigned long long ncr_d[64][64];

unsigned long long ncr(int n, int r) {
	if (ncr_d[n][r] > 0)
		return ncr_d[n][r];

	if (n == r || r == 0)
		return ncr_d[n][r] = 1;

	return ncr_d[n][r] = (ncr(n - 1, r - 1) + ncr(n - 1, r));
}

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(layer, layer + 12, 0);
	layer[0] = 1;

	for (int i = 1; i < 12; ++i)
		layer[i] += (layer[i - 1] + 8 * i);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n, k;
		cin >> n >> k;

		int layerNum = 0;
		for (layerNum = 0; layerNum < 12; ++layerNum) {
			if (n < layer[layerNum])
				break;
		}

		--layerNum;
		if (k <= layer[layerNum]) { // k가 layer타일수보다 작거나 같으면 확률은 무조건 1
			cout << "#" << test << " 1 / 1\n";
			continue;
		}

		if (k > layer[layerNum + 1]) { // k가 다음 layer타일수보다 크면 확률은 무조건 0
			cout << "#" << test << " 0 / 1\n";
			continue;
		}

		int left = n - layer[layerNum];

		if (left > 0 && k <= layer[layerNum] + 1) { // left가 1이상이면서 k가 layer타일수+1보다 작거나 같으면 확률은 무조건 1
			cout << "#" << test << " 1 / 1\n";
			continue;
		}

		if (left == 0 && k > layer[layerNum]) { // left가 0인데 k가 layer타일수보다 크면 확률은 무조건 0
			cout << "#" << test << " 0 / 1\n";
			continue;
		}
		else if (left == 1 && k > layer[layerNum] + 1) { // left가 1인데 k가 layer타일수+1보다 크면 확률은 무조건 0
			cout << "#" << test << " 0 / 1\n";
			continue;
		}

		// 이제부터는 계산
		--left;
		unsigned long long son = 0;
		unsigned long long mom = 0;
		int pos = k - 1 - layer[layerNum];

		for (int i = left; i > left / 2; --i) {     // left는 최소 1
			mom += 2 * ncr(left, i);
			if (i >= pos || 8 * (layerNum + 1) - pos <= left - i)
				son += ncr(left, i);
			if (left - i >= pos || 8 * (layerNum + 1) - pos <= i)
				son += ncr(left, i);
		}

		if (left % 2 == 0) { // 짝수개라면 하나더 계산 필요
			mom += ncr(left, left / 2);
			if (left / 2 >= pos || 8 * (layerNum + 1) - pos <= left / 2)
				son += ncr(left, left / 2);
		}

		if (son == 0)
			mom = 1;
		else {
			unsigned long long g = gcd(mom, son);
			mom /= g;
			son /= g;
		}
		cout << "#" << test << " " << son << " / " << mom << "\n";
	}

	return 0;
}