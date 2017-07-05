#include <iostream>
#include <vector>
using namespace std;

bool visit2[20][20] = { 0, };
char map[20][20];
int r, c;
int ans = 0;
int visit[32] = { 0, };
int cnt = 0;


void fuc(int x, int y, int cnt) {
	/*cout << "x : " << x << ", y : " << y << endl;
	cout << map[x][y] << endl;*/
	visit[map[x][y] - 65] = 1;

	// 우측
	if (y + 1<c)
		if (visit[map[x][y + 1] - 65] == 0) {
			visit[map[x][y + 1] - 65] = 1;
			fuc(x, y + 1,cnt+1);
		}

	// 아래
	if (x + 1<r)
		if (visit[map[x + 1][y] - 65] == 0) {
			visit[map[x + 1][y] - 65] = 1;
			fuc(x + 1, y,cnt+1);
		}

	// 왼쪽
	if (y - 1 >= 0)
		if (visit[map[x][y - 1] - 65] == 0) {
			visit[map[x][y - 1] - 65] = 1;
			fuc(x, y - 1,cnt+1);
		}

	// 아래
	if (x - 1 >= 0)
		if (visit[map[x - 1][y] - 65] == 0) {
			visit[map[x - 1][y] - 65] = 1;
			fuc(x - 1, y,cnt+1);
		}

	(ans < cnt) ? ans = cnt : 0;
	visit[map[x][y] - 65] = 0;
}

int main() {
	
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		char str[21];
		scanf("%s", str);

		int j = 0;
		while (str[j] != 0) {
			map[i][j] = str[j];
			j++;
		}
	}


	fuc(0,0,1);

	cout << ans << endl;
	return 0;
}