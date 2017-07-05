#include <iostream>
using namespace std;

int map[500][500];
int dp[500][500];
int m, n;
int ans = 0;


int solution(int x, int y) {

	if (x == m - 1 && y == n - 1) // ������ ����
		return 1;

	if (dp[x][y] != 0) // �̹� �ش� �������κ��� ���� ��ΰ� ����
		return dp[x][y];


	int tmp = 0;

	if (y + 1 <= n - 1) // ���� ���� : ���� ����� �ʰ�, ���̰� �� ���� ��
		if (map[x][y] > map[x][y + 1])
			tmp += solution(x, y + 1);

	if (x + 1 <= m - 1) // ���� ���� : ���� ����� �ʰ�, ���̰� �� ���� ��
		if (map[x][y] > map[x + 1][y])
			tmp += solution(x + 1, y);

	if (y - 1 >= 0) // ���� ���� : 0�� �̻��̸�, ���̰� �� ���� ��
		if (map[x][y] > map[x][y - 1])
			tmp += solution(x, y - 1);

	if (x - 1 >= 0) // ���� ���� : 0�� �̻��̸�, ���̰� �� ���� ��
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