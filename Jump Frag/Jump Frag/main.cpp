#include <iostream>
#include <vector>
using namespace std;

int Answer;
int dp[1000000] = { 0, };
int vec[1000000];

int main(int argc, char** argv)
{
	int T, test_case;
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		
		Answer = 0;

		int n;
		cin >> n;
		
		vec[0] = 0;

		for (int i = 1; i <= n; i++)
			scanf("%d",&vec[i]);

		

		int k;
		cin >> k;

		// first : coodinator , second : dp score
		fill_n(dp, 1000000, 0);
		

		for (int i = 1; i <= n; i++) {
			int min = 9999999;

			for (int j = i-1; j >= 0 && vec[j] >= vec[i]-k; j--) {
				if (dp[j] < min)
					min = dp[j];
			}

			dp[i] = min + 1;
		}

		Answer = (dp[n]== 9999999+1)?-1:dp[n];
		
		// Print the answer to standard output(screen).
		printf("Case #%d\n%d\n", test_case + 1, Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}