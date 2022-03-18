#include <iostream>

using namespace std;
int n, m, first, second, a, b,ans;
int map[101][101];
bool visited[101];
void dfs(int f, int s, int cnt) {
	visited[f] = true;
	if (f == s) {
		ans = cnt;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (map[f][i] == 1 && !visited[i]) {
			dfs(i, s, cnt + 1);
		}
	}
	return;
}
int main() {
	cin >> n >> first >> second >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	dfs(first,second,0);

	if (!ans) {
		cout << "-1";
	}
	else {
		cout << ans;
	}
	return 0;
}