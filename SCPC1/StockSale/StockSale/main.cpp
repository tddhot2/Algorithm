#include <iostream>
#include <vector>
using namespace std;

int Answer;
int n;
vector<int> vec;
vector<int> ans;

int main(int argc, char** argv)
{
	int T, test_case;
	

	freopen("input.txt", "r", stdin);

	cin >> T;
	printf("%d", T);
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;

		scanf("%d",&n);
		vec.resize(n);

		for (int i = 0; i < n; i++)
			scanf("%d",&vec[i]);


		ans.push_back(vec[0]);

		int flag = 0; // 0이 판매, 1이 구매

		for (int i = 1; i < n; i++) {
			if (flag == 0) {
				if (vec[i] > ans.back()) {
					ans.push_back(vec[i]);
					flag = 1;
				}
				else
					ans[ans.size()-1] = vec[i];
			}
			else {
				if (vec[i] < ans.back()) {
					ans.push_back(vec[i]);
					flag = 0;
				}
					
				else
					ans[ans.size() - 1] = vec[i];
			}
		}


		(ans.size() % 2 == 0)?Answer = ans.size() :Answer = ans.size()-1;

		vec.clear();
		ans.clear();

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;

		
	}

	return 0;//Your program should return 0 on normal termination.
}