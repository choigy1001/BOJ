#include <iostream>
#include <cstring>
using namespace std;
int T, N,cnt;
int graph[1001], visited[1001];
void dfs(int node) {
	visited[node] = 1;
	if (!visited[graph[node]]) {
		dfs(graph[node]);
	}
}
int main() {
	cin >> T;
	while (T--) {
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> graph[i];
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}