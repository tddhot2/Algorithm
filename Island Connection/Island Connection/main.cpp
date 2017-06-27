#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

typedef struct distance {
	int firstIsland;
	int secondIsland;
	int dis;
}Distance;

int Answer;

vector<int> ansVec;
vector<pair<int, int>> vec;
vector<Distance> distanceVec;
vector<int> vec2;
int n;
int cnt = 0;
int arr[4000] = { 0, };

bool compare(Distance u, Distance v) {
	if (u.dis < v.dis)
		return true;
	else
		return false;
}


int main(int argc, char** argv)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);
	cin >> T;

	

	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 100000000;

		cin >> n;

		// Input island's infomation (Pi : coordinator of island , Di : maximum connection number)
		for (int i = 0; i < n; i++) {
			int p, d;
			cin >> p;
			cin >> d;
			vec.push_back(make_pair(p, d));
		}


		for (int i = 0; i < vec.size(); i++) {
			for (int j = i + 1; j < vec.size(); j++) {
				int dis = vec[i].first - vec[j].first;
				(dis < 0) ? dis = dis*-1 : 0;
				Distance temp;
				temp.firstIsland = i;
				temp.secondIsland = j;
				temp.dis = dis;
				distanceVec.push_back(temp);
			}
		}
		
		vec2.push_back(0);
		while (1) {
			for (int i = vec2.back() + 1; i <= distanceVec.size(); i++) {
				//최대개수 도달시 pop이후 이전거에 +1한 것을 push
				if (vec2.size() == n - 1) {

					// calculating
					// Check that we can duild bridges
					fill_n(arr, 4000, 0);
					int tempAnswer = 0;

					// All island connected by bridge would be calculated
					for (int j = 0; j < vec2.size(); j++) {
						Distance temp;
						temp = distanceVec[vec2[j]];
						arr[temp.firstIsland]++;
						arr[temp.secondIsland]++;
						tempAnswer += temp.dis;
					}

					//cout << tempAnswer << endl;

					int k;
					for (k = 0; k < n; k++) {
						if (arr[k] == 0)
							break;

						if (vec[k].second - arr[k] < 0)
							break;
					}

					if (k == n)
						if (Answer > tempAnswer)
							Answer = tempAnswer;
					//calculating end()


					int temp = vec2.back() + 1;
					vec2.pop_back();
					vec2.push_back(temp);
				}
				else {
					vec2.push_back(i);
				}

				
			}

			vec2.pop_back();
			int temp = vec2.back() + 1;
			vec2.pop_back();
			vec2.push_back(temp);
			if (vec2.back() == distanceVec.size() - 1 && vec2.size() == 1)
				break;
		}



		// print Answer and setting initially
		(Answer == 100000000) ? Answer = -1 : 0;

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;

		vec.clear();
		vec2.clear();
		distanceVec.clear();
	}

	return 0;
}