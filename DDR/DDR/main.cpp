#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
int arr[2][100001];

int main() {
	vec.push_back(0);
	int a = 1;

	while (1) {
		scanf("%d", &a);
		if (a == 0)
			break;

		vec.push_back(a);
	}

	arr[0][0] = 0;
	arr[1][0] = 0;

	for (int i = 1; i <= vec.size(); i++) {
		//¿ÞÂÊ ÀÔ·Â
		int weight;
		if (vec[i - 1] == 0) {
			weight = 2;
		}
		else if ((vec[i-1]%2==1&&vec[i]%2==0)||(vec[i-1]%2==0&&vec[i]%2==1)) {
			weight = 3;
		}
		else if (vec[i - 1] == vec[i]) {
			weight = 1;
		}
		else {
			weight = 4;
		}

		arr[0][i] = (arr[0][i - 1] > arr[1][i - 1]) ? arr[1][i - 1] + weight : arr[0][i - 1] + weight;

	}

	return 0;
}