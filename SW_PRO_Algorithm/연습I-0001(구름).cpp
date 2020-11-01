#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
using namespace std;

char sky[101][101];

int main() {

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int h, w;
		cin >> h >> w;

		memset(sky, '.', sizeof(sky));

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j)
				cin >> sky[i][j];
		}

		cout << "#" << t << " ";
		for (int i = 0; i < h; ++i) {
			bool flag = false;
			int pos = 0;
			for (int j = 0; j < w; ++j) {
				if (!flag && sky[i][j] == '.')
					cout << -1 << " ";
				else {
					if (sky[i][j] == 'c') {
						flag = true;
						cout << 0 << " ";
						pos = j;
					}
					else
						cout << j - pos << " ";
				}
			}
			cout << "\n";
		}
	}

	return 0;
}

