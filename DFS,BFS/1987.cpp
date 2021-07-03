#include <iostream>
#include <algorithm>
using namespace std;
int r, c, ans;
bool visited[26];
char map[21][21];
string s;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void dfs(int x, int y, int cnt) {
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++) {
		int mx = x + dx[i];
		int my = y + dy[i];
		if (mx >= 0 && my >= 0 && mx < r && my < c) {
			if (visited[map[mx][my] - 'A'] == false) {
				visited[map[mx][my] - 'A'] = true;
				dfs(mx, my, cnt + 1);
				visited[map[mx][my] - 'A'] = false;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) {
			map[i][j] = s[j];
		}
	}

	visited[map[0][0] - 'A'] = true; //67-65 아스키코드
	dfs(0, 0, 1);
	cout << ans;
}