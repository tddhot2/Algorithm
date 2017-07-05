#include <iostream>
using namespace std;

int map[500][500];
int dp[500][500];
int m, n;
int ans = 0;


int solution(int x, int y) {

	if (x == m - 1 && y == n - 1) // 목적지 도착
		return 1;

	if (dp[x][y] != 0) // 이미 해당 지점으로부터 가는 경로가 존재
		return dp[x][y];


	int tmp = 0;

	if (y + 1 <= n - 1) // 우측 조건 : 열을 벗어나지 않고, 높이가 더 낮을 때
		if (map[x][y] > map[x][y + 1])
			tmp += solution(x, y + 1);

	if (x + 1 <= m - 1) // 하측 조건 : 행을 벗어나지 않고, 높이가 더 낮을 때
		if (map[x][y] > map[x + 1][y])
			tmp += solution(x + 1, y);

	if (y - 1 >= 0) // 좌측 조건 : 0열 이상이며, 높이가 더 낮을 때
		if (map[x][y] > map[x][y - 1])
			tmp += solution(x, y - 1);

	if (x - 1 >= 0) // 위측 조건 : 0행 이상이며, 높이가 더 낮을 때
		if (map[x][y] > map[x - 1][y])
			tmp += solution(x - 1, y);

	return dp[x][y]=tmp;
}

int main() {
	
	cin >> m >> n;

	for(int i=0;i<m;i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			dp[i][j] = 0;
		}
	
	solution(0, 0);

	cout << dp[0][0] << endl;

	return 0;
}