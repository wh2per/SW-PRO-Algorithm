#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

int arr[101][101];
int check[101][101];
vector<vector<pair<int, int>>> past;

const int dx[] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[] = { 0,1,1,1,0,-1,-1,-1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("./sample_input.txt", "r", stdin);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        int n;
        cin >> n;

        memset(arr, 0, sizeof(arr));
        memset(check, false, sizeof(check));
        past.assign(n + 1, vector<pair<int, int>>(n + 1, pair<int, int>()));

        // 맵 입력 
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                cin >> arr[i][j];
        }

        // 큐 
        queue<pair<int, int>> q;
        q.push({ n,n });
        check[n][n] = true;
        bool flag = false;

        while (!q.empty()) {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();

            if (cy == 1 && cx == 1) {        // 도착시 탈출
                flag = true;
                break;
            }

            for (int k = 0; k < 8; ++k) {
                int ny = cy + dy[k];
                int nx = cx + dx[k];

                if (ny <= 0 || ny > n || nx <= 0 || nx > n)        // 맵 밖
                    continue;
                if (check[ny][nx] || arr[ny][nx] == 1)        // 방문 or 벽
                    continue;

                past[ny][nx] = { cy,cx };        // 이전 지점 등록
                check[ny][nx] = true;
                q.push({ ny,nx });
            }
        }

        cout << "#" << t << " ";
        if (!flag) {
            cout << "0\n";
            continue;
        }
        int ny = 1;
        int nx = 1;
        cout << "1 1 ";
        while (ny != n || nx != n) {
            int nny = past[ny][nx].first;
            int nnx = past[ny][nx].second;
            ny = nny;
            nx = nnx;
            cout << ny << " " << nx << " ";
        }
        cout << "\n";
    }


    return 0;
}