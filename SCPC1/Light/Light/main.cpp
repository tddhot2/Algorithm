#include <iostream>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;


	freopen("input.txt", "r", stdin);

	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;



		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}