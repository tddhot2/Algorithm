#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> g[10001]; // 인접리스트 그래프 벡터
stack<int> stk;
int di[10001] = { -1, }; // 각 정점별 진출차수 개수
int idx[10001] = { 0, }; //각 인덱스를 저장할 배열
int n, m;
int Max = 0;

void printDi() {
	cout << "진출차수 배열" << endl;
	for (int i = 0; i <= n; i++)
		cout << di[i] << " ";
	cout << "\n";
}

void printIdx() {
	cout << "인덱스 배열" << endl;
	for (int i = 1; i <= n; i++)
		cout << idx[i] << " ";
	cout << "\n";
}


int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		// a가 b를 신뢰한다. b->a 방향 그래프
		int a, b;
		scanf("%d %d", &a, &b);
		g[b].push_back(a);
	}

	fill_n(di, 10001, -1);


	for (int i = 1; i <= n; i++) {
		// i정점의 진출 배열 값이 -1이라면, 아직 개수를 파악하지 못한 것이므로, 이를 기준으로 DFS시작
		if (di[i] == -1) {
			int visited[10001] = { 0, };

			stk.push(i);

			//stack이 전부비면 DFS가 완료됨
			while (!stk.empty()) {
				cout << stk.size() << endl;
				cout << visited[1] << visited[2] << visited[3] << endl;
				int now = stk.top();
				visited[now] = 1;

				if (idx[now] == g[now].size()) {
					stk.pop();
				}
				else {
					// 스택의 차상위 정점의 연결된 정점이 단말정점일 경우 : 단말정점 개수를 0개로, 자신은 하나추가
					if (g[g[now][idx[now]]].size() == 0) {
						(di[now] == -1) ? di[now] = 1 : di[now]++;
						di[g[now][idx[now]]] = 0;
						idx[now]++;
					}
					// 이미 정점 계산이 끝난 정점일 경우
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