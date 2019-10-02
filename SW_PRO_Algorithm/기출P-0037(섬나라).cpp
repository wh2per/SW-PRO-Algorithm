#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M, Q;
int A[505][505];
int q1[100005], C[100005];
int MAX;
int P[250005], num[505][505];
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
int cnt;
vector<pair<int, int> > v[100005];
int ans[100005];

int find(int a) {
	if (P[a] == a) return a;
	return P[a] = find(P[a]);
}

void merge(int n) {
	int x, y, nx, ny;
	for (int i = 0; i < v[n].size(); i++) {
		x = v[n][i].first;
		y = v[n][i].second;
		P[num[x][y]] = num[x][y]; cnt++;
		for (int d = 0; d < 4; d++) {
			nx = x + dx[d]; ny = y + dy[d];
			if (nx > 0 && nx <= N && ny > 0 && ny <= M && P[num[nx][ny]] != 0) {
				int pa = find(num[x][y]);
				int pb = find(num[nx][ny]);

				if (pa == pb) continue;
				P[pa] = pb; cnt--;
			}
		}
	}
	v[n].clear();
}

int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &N, &M);
		MAX = 0; int c = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				scanf("%d", &A[i][j]);
				MAX = max(MAX, A[i][j]);
				num[i][j] = ++c;
				v[A[i][j]].push_back(make_pair(i, j));
			}
		}

		scanf("%d", &Q);
		for (int q = 1; q <= Q; q++) {
			scanf("%d", &q1[q]);
			if (C[q1[q]] == 0) C[q1[q]] = q;
		}

		cnt = 0;
		for (int i = 1; i <= MAX; i++) {
			if (!C[i]) merge(i);
		}

		for (int q = Q; q > 0; q--) {
			ans[q] = cnt;
			if (C[q1[q]] == q) merge(q1[q]);
		}
		printf("#%d ", t);
		for (int i = 1; i <= Q; i++) printf("%d ", ans[i]);
		printf("\n");

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				A[i][j] = num[i][j] = 0;
			}
		}

		for (int i = 1; i <= Q; i++) ans[i] = 0;
		for (int i = 1; i <= c; i++) P[i] = 0;
		for (int i = 1; i <= MAX; i++) C[i] = 0, v[i].clear();

	}
	return 0;
}