#include <iostream>
#include <map>
using namespace std;

// F(2n-1) = F(n)^2 + F(n-1)^2
// F(2n) = (F(n-1) + F(n+1)) * F(n) = (2F(n-1) + F(n)) * F(n)

map<long long, long long> fibo_d;
const long long mod = 1000000007LL;

long long fibo(long long n) {
	if (n <= 0)
		return 0;
	else if (n == 1 || n == 2)
		return 1;
	else if (fibo_d.count(n) > 0)		// 이미 존재하면
		return fibo_d[n];
	else {
		if (n % 2 == 1) {		// 홀수번째 피보나치수
			long long m = (n + 1) / 2;
			long long t1 = fibo(m);
			long long t2 = fibo(m - 1);
			fibo_d[n] = t1*t1 + t2*t2;
			fibo_d[n] %= mod;
			return fibo_d[n];
		}
		else {					// 짝수번째 피보나치수
			long long m = n / 2;
			long long t1 = fibo(m-1);
			long long t2 = fibo(m);
			fibo_d[n] = (2LL * t1 + t2)*t2;
			fibo_d[n] %= mod;
			return fibo_d[n];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;

	fibo_d.clear();
	for (int t = 1; t <= tc; ++t) {
		long long n;
		cin >> n;
		cout << "#" << t << " " << fibo(n) << "\n";
	} 
	return 0;
}