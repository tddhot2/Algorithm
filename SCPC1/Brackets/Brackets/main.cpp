#include <iostream>
#include <vector>
using namespace std;

int Answer;
char str[1000000];
vector<char> vec;
vector<char> ans;


int main(int argc, char** argv)
{
	int T, test_case;
	freopen("input.txt", "r", stdin);

	cin >> T;
	getchar();
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		scanf("%[^\n]s", str);
		getchar();
		int idx = 0; // 문자열의 문자를 가르킬 인덱스
		char c; //문자열에 해당 문자를 저장할 인스턴스

		// 매 테스트케이스마다 벡터들을 초기화함
		vec.clear();
		ans.clear();

		vec.push_back('~');


		while (str[idx] != 0) {
			c = str[idx];

			// 닫힌 괄호를 만나면 벡터의 맨끝과 비교하여 올바를경우 벡터를 pop하고 2를 집어넣는다.
			if (c == ')' || c == ']' || c == '}') 
			{
				int check = (int)c + (int)vec.back();
				if (check == 81 || check == 184 || check == 248) {
					// 올바른 괄호 부분
					vec.pop_back();

					if (ans.back() != '2')
						ans.pop_back();

					ans.push_back('2');
				}
				else {
					// 올바르지 못한 괄호를 만남
					vec.clear();
					vec.push_back('~');
					ans.push_back('-');
				}
			}
			else if (c == ' ') {
				ans.push_back('1');
			}
			else //열린 괄호를 만났을 때
			{
				vec.push_back(c);
				ans.push_back(c);
			}
			idx++;
		}
		

		int temp = 0;
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] == '1') {
				temp++;
			}
			else if (ans[i] == '2') {
				temp += 2;
			}
			else {
				(Answer < temp) ? Answer = temp : 0;
				temp = 0;
			}
		}

		(Answer < temp) ? Answer = temp : temp = 0;
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}