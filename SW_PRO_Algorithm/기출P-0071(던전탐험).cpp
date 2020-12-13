#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

vector<pair<int, int>> info[1001];
long long dist[1001][2];
int parent[1001];

int go(int end) {
    if (end == 0 || end == -1)
        return end;
    return go(parent[end]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("sample_input.txt", "r", stdin);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; ++t) {
        int v, e, a;
        cin >> v >> e >> a;

        for (int i = 0; i < v; ++i) {        // 초기화
            info[i].clear();
            dist[i][0] = INT_MAX;
            dist[i][1] = 0;
            parent[i] = -1;
        }

        while (e--) {
            int x, y, z;
            cin >> x >> y >> z;

            info[x].push_back({ y,z });
            info[y].push_back({ x,z });
        }

        while (a--) {
            int x, y, z;
            cin >> x >> y >> z;

            info[x].push_back({ y,-z });
        }

        dist[0][0] = 0;

        for (int i = 0; i < v - 1; ++i) {       // 1 ~ v-1번 순회 
            for (int j = 0; j < v - 1; ++j) {       // 시작정점 1~v 순회 
                for (int k = 0; k < info[j].size(); ++k) {
                    if (dist[info[j][k].first][0] > dist[j][0] + info[j][k].second || (dist[info[j][k].first][0] == dist[j][0] + info[j][k].second && dist[info[j][k].first][1] > dist[j][1])) {
                        dist[info[j][k].first][0] = dist[j][0] + info[j][k].second;

                        dist[info[j][k].first][1] = dist[j][1];
                        if (info[j][k].second < 0)
                            ++dist[info[j][k].first][1];
                        parent[info[j][k].first] = j;
                    }
                }
            }
        }

        bool flag = false;
        for (int j = 0; j < v - 1; ++j) {       // 정점 1~v 순회 
            for (int k = 0; k < info[j].size(); ++k) {
                if (dist[info[j][k].first][0] > dist[j][0] + info[j][k].second) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }

        cout << "#" << t << " ";
        if (flag)
            cout << "BUG\n";
        else {
            if (go(v - 1) == -1)
                cout << "NO\n";
            else {
                cout << dist[v - 1][0] << " " << dist[v - 1][1] << "\n";
            }
        }
    }

    return 0;
}