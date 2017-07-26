#include <iostream>

using namespace std;

int Answer;
int n;
int	s[5];
int l[5];
int d[5];


int main(int argc, char** argv)
{
	int T, test_case;


	freopen("input.txt", "r", stdin);

	cin >> T;
	cout << T << endl;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			s[i] = a;
			l[i] = b;
			d[i] = c;
		}

		while (1) {
			int flag = 0;

			for(int i=0;i<n;i++)
				if ((d[i] + (s[i] * Answer)) % l[i] != 0) {
					Answer++;
					continue;
				}
			break;
		}

		cout << "debug point" << endl;

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}