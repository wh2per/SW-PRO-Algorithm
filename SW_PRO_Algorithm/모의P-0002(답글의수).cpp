#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int M, ops[100001][2], post_no, in[50001], out[50001], order;
vector<int> children[50001];

long long tree[1 << 18];

void init() {
    for (int i = 0; i <= 50000; i++)
        children[i].clear();
    memset(tree, 0, sizeof(tree));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    post_no = 0;
    order = -1;
}

void dfs(int root) {
    in[root] = ++order;
    for (int child : children[root])
        dfs(child);
    out[root] = order;
}

void add_node(int node, int start, int end, int idx) {
    if (idx < start || end < idx)
        return;
    tree[node]++;
    if (start != end) {
        add_node(2 * node, start, (start + end) / 2, idx);
        add_node(2 * node + 1, (start + end) / 2 + 1, end, idx);
    }
}

void delete_node(int node, int start, int end, int i, int j) {
    if (j < start || end < i)
        return;
    else if (i <= start && end <= j)
        tree[node] = 0;
    else {
        delete_node(2 * node, start, (start + end) / 2, i, j);
        delete_node(2 * node + 1, (start + end) / 2 + 1, end, i, j);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

long long query(int node, int start, int end, int i, int j) {
    if (j < start || end < i)
        return 0;
    if (i <= start && end <= j)
        return tree[node];
    return query(2 * node, start, (start + end) / 2, i, j) + query(2 * node + 1, (start + end) / 2 + 1, end, i, j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        init();
        cin >> M;
        for (int i = 1; i <= M; i++) {
            cin >> ops[i][0] >> ops[i][1];
            if (ops[i][0] == 1)
                children[ops[i][1]].push_back(++post_no);
        }

        dfs(0);

        long long ans = 0;
        post_no = 0;
        for (int i = 1; i <= M; i++) {
            int op = ops[i][0], x = ops[i][1];
            if (op == 1) {
                post_no++;
                add_node(1, 1, order, in[post_no]);
            }
            else if (op == 2) {
                delete_node(1, 1, order, in[x], out[x]);
            }
            else if (op == 3) {
                ans += query(1, 1, order, in[x], out[x]) - 1;
            }
        }

        cout << '#' << t << ' ' << ans << '\n';
    }

    return 0;
}