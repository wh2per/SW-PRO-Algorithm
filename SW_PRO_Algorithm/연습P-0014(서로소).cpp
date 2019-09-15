#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd_each(int a, int b) {		// 최대공약수
	if (a%b == 0)
		return b;
	else
		return gcd_each(b, a%b);
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

		vector<int> v;
		vector<int> dp(100001,0);
		dp.push_back(0);
		for (int i = 0; i < n; ++i) {
			int num;
			cin >> num;

			for (int j = 0; j < 100001; ++j) {
				if (dp[j] != 0) {
					int g = gcd_each(j,num);
					dp[g] = (dp[g] + dp[j]) % 10000003;
				}
			}
			++dp[num];
			v.push_back(num);
		}

		cout << "#" << t << " " << dp[1] << "\n";
	}
	return 0;
}

/*
#include <iostream>
#include <cstring>
using namespace std;
int dp[101][100001];
int arr[100001];
int mod = 10000003;
int n;
int getGcd(int a, int b) {
	if (b>a)swap(a, b);
	if (b == 0)return a;
	return getGcd(b, a%b);
}
int go(int pos, int gcd) {
	int &ans = dp[pos][gcd];
	if (pos == n + 1) {
		if (gcd == 1)return 1;
		else return 0;
	}
	if (ans != -1)return ans;
	int a, b;
	if (gcd == 0) {  //아직 아무것도 집합에 추가안한상태
		a = go(pos + 1, arr[pos]);
		b = go(pos + 1, 0);
	}
	else {
		a = go(pos + 1, getGcd(gcd, arr[pos]));  //pos번째 원소를 뽑음
		b = go(pos + 1, gcd);  //pos번째 원소를 뽑지 않음
	}
	ans = (a%mod + b%mod) % mod;
	return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		cout << "#" << tc << " " << go(1, 0) << endl;
	}
	return 0;
}


#include <stdio.h>

using namespace std;
const int MOD = 10000003;
int N;
int D[101][100001];

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i <= 100; i++) for (int j = 0; j <= 100000; j++) D[i][j] = 0;
		scanf("%d", &N);
		D[0][0] = 1;

		for (int i = 0; i<N; i++) {
			int v;
			scanf("%d", &v);
			for (int j = 0; j<100001; j++) 
				if (D[i][j]) {
					D[i + 1][j] = (D[i + 1][j] + D[i][j]) % MOD;
					D[i + 1][gcd(j, v)] = (D[i + 1][gcd(j, v)] + D[i][j]) % MOD;
				}
			}
		}

		printf("#%d %d\n", tc, D[N][1]);
	}
}

*/