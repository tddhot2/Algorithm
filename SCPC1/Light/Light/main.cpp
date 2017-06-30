#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct _lightinfo {
	bool status;
	int r;
	int c;
}LI;

int Answer;
int n, m;
LI map[100][100];
vector<string> ans;

void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << map[i][j].status<<" ";
		cout << "\n";
	}
	cout << "\n";
}


int main(int argc, char** argv)
{
	int T, test_case;


	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int s, a, b;
				scanf("%d %d %d", &s, &a, &b);
				map[i][j].status = s;
				map[i][j].r = a;
				map[i][j].c = b;
			}
		}
		
				
		while (1) {
			int flag = 0; // 반복문 이후 flag가 그대로 0이면 성공

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (map[i][j].status == 0) {
						//cout << "행 : " << i << ", 열 : " << j << endl;
						flag = 1;
						// 해당 전구가 꺼져있음
						// 행과 열의 스위치번호를 판별하여, 각 행과 열의 스위치에 해당하는 전구들 중 꺼져있는애들이
						// 많은 스위치를 눌러서 키도록 변경
						string str;
						int rnum = map[i][j].r;
						int cnum = map[i][j].c;

						int offRnum = 0;
						for (int k = 0; k < m; k++)
							if (map[i][k].r == rnum && map[i][k].status == 0)
								offRnum++;

						int offCnum = 0;
						for (int k = 0; k < n; k++)
							if (map[k][j].c == cnum && map[k][j].status == 0)
								offCnum++;

						if (offRnum > offCnum) {
							(i < 10) ? str = "R0" + to_string(i) : str = "R" + to_string(i);
							(rnum < 10) ? str += "0"+ to_string(rnum) : str += to_string(rnum);

							for (int k = 0; k < m; k++)
								(map[i][k].r == rnum) ? map[i][k].status = !map[i][k].status : 0;
						}
						else {
							(j < 10) ? str = "C0" + to_string(j) : str = "C" + to_string(j);
							(cnum < 10) ? str += "0" + to_string(cnum) : str += to_string(cnum);

							for (int k = 0; k < n; k++)
								(map[k][j].c == cnum) ? map[k][j].status = !map[k][j].status : 0;
						}
						//printMap();
						ans.push_back(str);
					}
				}
			}

			if (flag == 0)
				break;
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << "\n";

		ans.clear();
	}

	return 0;//Your program should return 0 on normal termination.
}