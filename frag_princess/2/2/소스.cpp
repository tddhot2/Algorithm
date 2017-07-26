#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
char str[100001];
vector<pair<int, vector<int>>> vec;

int main() {
	cin >> n >> k;
	cin >> str;
	vector<pair<int, vector<int>>>::iterator insertPtr;

	vec.resize(100000);

	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		insertPtr = lower_bound(vec.begin(), vec.end(), x);
		if (insertPtr->first == x) {
			insertPtr->second.push_back(y);
		}
		else {
			vec[vec.size()].first = x;
			vec[vec.size()].second.push_back(y);
		}
	}

	for (int i = 0; i < vec[0].second.size(); i++)
		cout << vec[0].second[i] << endl;

}