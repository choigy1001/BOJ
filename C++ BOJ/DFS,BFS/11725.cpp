#include <iostream>
#include <vector>

#define MAX 100001
using namespace std;
int N, s,e;
vector <int> v[MAX];
int parent[MAX];
bool visited[MAX];
void find_p(int node) {
	visited[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		int nextnode = v[node][i];
		if (!visited[nextnode]) {
			parent[nextnode] = node;
			find_p(nextnode);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);//��������� ����� ���������� �۵� �θ� ã�� ����
	}
	find_p(1);
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
	return 0;
}