#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int map[51][51];
int visited[51][51];
//대각선도 하나의 섬으로 간주하기때문
int dx[] = { 1,-1,0,0 ,1,1,-1,-1};
int dy[] = { 0,0,1,-1 ,1,-1,1,-1};
int w, h,island;
void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 8; i++) {
		int mx = x + dx[i];
		int my = y + dy[i];
		if (0 <= mx && 0 <= my && mx < w && my < h) {
			if (!visited[my][mx] && map[my][mx]) {
				dfs(my, mx);
			}
		}
	}
}
int main() {
	
	while (1) {
		cin >> w >> h;
		if (!w && !h)
			break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] && !visited[i][j]) {
					island++;
					dfs(i, j);
				}
			}
		}
		cout << island << "\n";
		island = 0;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}