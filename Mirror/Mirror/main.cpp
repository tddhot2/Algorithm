#include <iostream>
#include <vector>
using namespace std;

int main() {
	int row, col;
	cin >> row >> col;

	vector<vector<int>> map(row + 2, vector<int>(col + 2, 0));

	int num = 2;

	for (int i = 1; i <= row; i++) 
		map[i][0] = num++;
	for (int i = 1; i <= col; i++)
		map[row+1][i] = num++;
	for (int i = row; i >= 1; i--)
		map[i][col+1] = num++;
	for (int i = col; i >= 1; i--)
		map[0][i] = num++;

	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			cin >> map[i][j];

	// Left Side
	for (int i = 1; i <= row; i++) {
		int x = i;
		int y = 1;
		int flag = 0; // move right
		while (map[x][y] < 2) {
			if (map[x][y] == 1)
				(flag == 0) ? flag = 1 : flag = 0;

			if (flag == 0)
				y++;
			else
				x--;
		}
		cout << map[x][y]-1 << " ";
	}

	// Up Side
	for (int i = 1; i <= col; i++) {
		int x = row;
		int y = i;
		int flag = 0; // move up
		while (map[x][y] < 2) {
			if (map[x][y] == 1)
				(flag == 0) ? flag = 1 : flag = 0;

			if (flag == 0)
				x--;
			else
				y++;
		}
		cout << map[x][y] - 1 << " ";
	}

	// Left Side
	for (int i = row; i >= 1; i--) {
		int x = i;
		int y = col;
		int flag = 0; // move left
		while (map[x][y] < 2) {
			if (map[x][y] == 1)
				(flag == 0) ? flag = 1 : flag = 0;

			if (flag == 0)
				y--;
			else
				x++;
		}
		cout << map[x][y] - 1 << " ";
	}

	// Left Side
	for (int i = col; i >= 1; i--) {
		int x = 1;
		int y = i;
		int flag = 0; // move down
		while (map[x][y] < 2) {
			if (map[x][y] == 1)
				(flag == 0) ? flag = 1 : flag = 0;

			if (flag == 0)
				x++;
			else
				y--;
		}
		cout << map[x][y] - 1 << " ";
	}
	return 0;
}