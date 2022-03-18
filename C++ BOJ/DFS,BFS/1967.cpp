#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;
int n, from, to, weight, diameter, farnode;
vector<pair<int, int>> v[10001];
bool visited[10001];
void dfs(int node, int cost) {
	if (visited[node]) {
		return;
	}
	visited[node] = true;
	if (diameter < cost) {
		diameter = cost;
		farnode = node;
	}
	for (int i = 0; i < v[node].size(); i++) {
		dfs(v[node][i].first, cost+v[node][i].second);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> from >> to >> weight;
		v[from].push_back({ to,weight });
		v[to].push_back({ from, weight });
	}
	//1���� ���� �� ��带 ã���� �� ��忡�� ���� �ָ��ִ� ������ �Ÿ��� ����
	dfs(1, 0);
	
	memset(visited, 0, sizeof(visited));
	
	dfs(farnode, 0);
	cout << diameter;
	return 0;
}