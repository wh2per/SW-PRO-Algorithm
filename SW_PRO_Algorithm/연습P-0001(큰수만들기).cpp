#include <iostream>
#include <vector>
using namespace std;

char number[500001];

int main() {
	int tc;
	scanf("%d",&tc);

	for (int t = 1; t <= tc; ++t) {
		int n, k;
		scanf("%d %d %s",&n,&k,&number);

		vector<int> v;
		v.push_back(number[0] - '0');
		int i;
		for (i = 1; i < n; ++i) {
			if (v.back() < number[i]-'0') {		// 나보다 크면
				while (v.size() > 0 && v.back() < number[i] - '0') {
					v.pop_back();
					--k;
					if (k == 0)
						break;
				}
				v.push_back(number[i] - '0');
				if (k == 0)
					break;
			}
			else 
				v.push_back(number[i] - '0');
		}
		for (int j = i + 1; j < n; ++j)
			v.push_back(number[j] - '0');
		for (int i = k; i > 0; --i)
			v.pop_back();

		printf("#%d ",t);
		for (auto a : v)
			printf("%d",a);
		printf("\n");
	}
	return 0;
}
