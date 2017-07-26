#include <iostream>
#include <vector>
using namespace std;

int Answer;
vector<int> vec; // Áö·Ú À§Ä¡

int main(int argc, char** argv)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;

		int n, k, l;
		cin >> n >> k >> l;

		while (l) {
			int tmp;
			scanf("%d", &tmp);
			vec.push_back(tmp);
			l--;
		}




		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}