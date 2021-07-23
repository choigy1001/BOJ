#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
int V, from, to, weight, diameter, farnode;
vector<pair<int, int>> v[100001];
bool visited[100001];
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
		dfs(v[node][i].first, cost + v[node][i].second);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> V;
	for (int i = 0; i < V; i++) {
		cin >> from;
		while (1) {
			cin >> to;
			if (to == -1) {
				break;
			}
			cin >> weight;
			v[from].push_back({ to,weight });
			//간선정보가 노드마다 다 있기때문에 양방향으로 할필요 x
			//v[to].push_back({ from,weight });
		}
	}
	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	dfs(farnode, 0);
	cout << diameter;
	return 0;
}