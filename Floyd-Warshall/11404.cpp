#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321

using namespace std;
int graph[101][101];
int n, m, a, b, c;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			graph[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (graph[a][b] == INF) {
			graph[a][b] = c;
		}
		else {
			graph[a][b] = min(graph[a][b], c);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (graph[j][i] != INF && graph[i][k] != INF && graph[j][k] > graph[j][i] + graph[i][k]) {
					graph[j][k] = graph[j][i] + graph[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || graph[i][j]==INF) {
				cout << 0 << " ";
			}
			else {
				cout << graph[i][j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}