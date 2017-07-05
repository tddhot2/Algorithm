#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> g[10001]; // ��������Ʈ �׷��� ����
stack<int> stk;
int di[10001] = { -1, }; // �� ������ �������� ����
int idx[10001] = { 0, }; //�� �ε����� ������ �迭
int n, m;
int Max = 0;

void printDi() {
	cout << "�������� �迭" << endl;
	for (int i = 0; i <= n; i++)
		cout << di[i] << " ";
	cout << "\n";
}

void printIdx() {
	cout << "�ε��� �迭" << endl;
	for (int i = 1; i <= n; i++)
		cout << idx[i] << " ";
	cout << "\n";
}


int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		// a�� b�� �ŷ��Ѵ�. b->a ���� �׷���
		int a, b;
		scanf("%d %d", &a, &b);
		g[b].push_back(a);
	}

	fill_n(di, 10001, -1);


	for (int i = 1; i <= n; i++) {
		// i������ ���� �迭 ���� -1�̶��, ���� ������ �ľ����� ���� ���̹Ƿ�, �̸� �������� DFS����
		if (di[i] == -1) {
			int visited[10001] = { 0, };

			stk.push(i);

			//stack�� ���κ�� DFS�� �Ϸ��
			while (!stk.empty()) {
				cout << stk.size() << endl;
				cout << visited[1] << visited[2] << visited[3] << endl;
				int now = stk.top();
				visited[now] = 1;

				if (idx[now] == g[now].size()) {
					stk.pop();
				}
				else {
					// ������ ������ ������ ����� ������ �ܸ������� ��� : �ܸ����� ������ 0����, �ڽ��� �ϳ��߰�
					if (g[g[now][idx[now]]].size() == 0) {
						(di[now] == -1) ? di[now] = 1 : di[now]++;
						di[g[now][idx[now]]] = 0;
						idx[now]++;
					}
					// �̹� ���� ����� ���� ������ ���
					else if (di[g[now][idx[now]]]>0) {
						(di[now] == -1) ? di[now] = 0 : 0;
						di[now] += di[g[now][idx[now]]] + 1;
						idx[now]++;
					}
					else {
						cout << g[now][idx[now]] << endl;
						if (visited[g[now][idx[now]]] == 0)
							stk.push(g[now][idx[now]]);
						else
							idx[now]++;
					}
				}

				if (di[now] > Max)
					Max = di[now];
			}
		}
	}

	for (int i = 1; i <= n; i++)
		(di[i] == Max) ? printf("%d ", i) : 0;

	return 0;
}