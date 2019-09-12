#include <iostream>
using namespace std;

int paper[129][129];
int b_paper;
int w_paper;

void check_paper(int width, int sx, int sy) {
	if (width == 0)
		return;

	// ���� �˻�
	int w = 0, b = 0;
	for (int i = sy; i<sy + width; ++i) {
		for (int j = sx; j<sx + width; ++j) {
			if (paper[i][j] == 1)
				++b;
			else
				++w;
		}
	}
	if (b == width*width)
		++b_paper;
	else if (w == width*width)
		++w_paper;
	else {          // �˻��� ���ж�� depth+1 �� �˻����
		check_paper(width / 2, sx, sy);
		check_paper(width / 2, sx + width / 2, sy);
		check_paper(width / 2, sx, sy + width / 2);
		check_paper(width / 2, sx + width / 2, sy + width / 2);
	}
	return;
}

int A_0028() {
	int t;
	scanf("%d",&t);
	for (int k = 1; k <= t; ++k) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i<n; ++i) {
			for (int j = 0; j<n; ++j)
				scanf("%d", &paper[i][j]);
		}

		w_paper = 0;
		b_paper = 0;
		check_paper(n, 0, 0);
		printf("#%d %d %d\n",k,w_paper,b_paper);
	}
	return 0;
}