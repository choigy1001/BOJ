#include <iostream>
#include <cstring>
using namespace std;
int N, cnt;
bool visited[101][101];
char map[101][101];
string s;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int mx = x + dx[i];
		int my = y + dy[i];
		if (0 <= mx && 0 <= my && mx < N && my < N) {
			if (!visited[mx][my] && map[x][y] == map[mx][my]) {
				dfs(mx, my);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			map[i][j] = s[j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << " ";
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'G') {
				map[i][j] = 'R';
			}
		}
	}
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
	}