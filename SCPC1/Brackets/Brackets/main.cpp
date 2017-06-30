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
		int idx = 0; // ���ڿ��� ���ڸ� ����ų �ε���
		char c; //���ڿ��� �ش� ���ڸ� ������ �ν��Ͻ�

		// �� �׽�Ʈ���̽����� ���͵��� �ʱ�ȭ��
		vec.clear();
		ans.clear();

		vec.push_back('~');


		while (str[idx] != 0) {
			c = str[idx];

			// ���� ��ȣ�� ������ ������ �ǳ��� ���Ͽ� �ùٸ���� ���͸� pop�ϰ� 2�� ����ִ´�.
			if (c == ')' || c == ']' || c == '}') 
			{
				int check = (int)c + (int)vec.back();
				if (check == 81 || check == 184 || check == 248) {
					// �ùٸ� ��ȣ �κ�
					vec.pop_back();

					if (ans.back() != '2')
						ans.pop_back();

					ans.push_back('2');
				}
				else {
					// �ùٸ��� ���� ��ȣ�� ����
					vec.clear();
					vec.push_back('~');
					ans.push_back('-');
				}
			}
			else if (c == ' ') {
				ans.push_back('1');
			}
			else //���� ��ȣ�� ������ ��
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