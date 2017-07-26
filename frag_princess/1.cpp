#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// Data Structure
int n;
int k;
char str[100001];
vector<pair<int,int>> vec;

void printVec() {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i].first << "," << vec[i].second << " ";
	cout << "\n";
}

int main() {
	cin >> n;
	cin >> k;
	cin >> str;

	int x, y;
	scanf("%d %d", &x, &y);
	vec.push_back(make_pair(x, y));

	for (int i = 1; i < n; i++) {
		int tmpx, tmpy;
		scanf("%d %d", &tmpx, &tmpy);
		vec.push_back(make_pair(tmpx, tmpy));
	}

	sort(vec.begin(), vec.end());

	int strIdx = 0;

	for (int i = 0; i < k; i++) {
		int flag = 0;
		/*cout << "x = " << x << " , y = " << y << endl;
		printVec();*/

		vector<pair<int, int>>::iterator removeP;
		vector<pair<int, int>>::iterator p = lower_bound(vec.begin(), vec.end(), make_pair(x, y));
		removeP = p;

		

		// Switch ~
		switch (str[strIdx])
		{
			case 'A': 
			{
				for (; p != vec.end(); p++) {
					cout << p->first << "," << p->second << endl;
					if (p->first - x == p->second - y && p->second > y) {
						flag = 1;
						x = p->first;
						y = p->second;
						vec.erase(removeP);
						break;
					}
				}
				break;
			}
			case 'B': 
			{
				for (; p != vec.end(); p++) {
					if (p->first - x == y - p->second && p->second < y) {
						flag = 1;
						x = p->first;
						y = p->second;
						vec.erase(removeP);
						break;
					}
				}
				break;
			}
			case 'C': 
			{
				for (; p != vec.begin(); --p) {
					if (x - p->first == p->second - y && p->second > y) {
						flag = 1;
						x = p->first;
						y = p->second;
						vec.erase(removeP);
						break;
					}
				}
				break;
			}
			case 'D': 
			{
				for (; p >= vec.begin(); p--) {
					if (x - p->first == y - p->second && p->second < y) {
						flag = 1;
						x = p->first;
						y = p->second;
						vec.erase(removeP);
						break;
					}
				}
				break;
			}
		}
		// ~ Switch

		if (flag == 0)
			break;

		strIdx++;
	}

	cout << x << " " << y << endl;

	return 0;
}