#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <climits>
using namespace std;

int arr[101];
int dp[101][101];

int search(int start, int end) {
    int temp = 0;
    int right = 0;
    int left = 0;

    if (start > end)
        return 0;

    if (dp[start][end] != INT_MAX)
        return dp[start][end];

    if (start == end) {
        dp[start][end] = arr[start];
        return arr[start];
    }
    else {
        for (int i = start; i <= end; ++i) {
            left = search(start, i - 1);
            right = search(i + 1, end);

            temp = arr[i] + max(left, right);
            dp[start][end] = min(dp[start][end], temp);
        }
    }

    return dp[start][end];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        string s;
        cin >> s;

        int len = s.length();
        memset(arr, 0, sizeof(arr));
        fill(&dp[0][0], &dp[len][len], INT_MAX);

        for (int i = 0; i < len; ++i)
            arr[i] = s[i] - '0';


        search(0, len - 1);

        cout << "#" << t << " " << dp[0][len - 1] << "\n";
    }

    return 0;
}