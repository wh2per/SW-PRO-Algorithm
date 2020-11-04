#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int main(int argc, char** argv) {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; ++t) {
        int n, m;
        cin >> n >> m;

        vector<set<int> > info(n + 1);

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            info[a].insert(b);
        }

        int ans = 1;
        for (int i = 1; i <= n; ++i) {
            int cnt = 0;
            queue<int> q;
            vector<bool> check(n + 1, false);
            q.push(i);
            check[i] = true;

            while (!q.empty()) {
                int d = q.front();
                cnt++;
                q.pop();

                for (auto a : info[d]) {
                    if (!check[a]) {
                        q.push(a);
                        check[a] = true;
                    }
                }
            }
            if (cnt > ans)
                ans = cnt;
        }
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}

