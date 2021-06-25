#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
int N, minh, maxh;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue <pii> q;
int map[101][101];
int visited[101][101];

void bfs(int x, int y, int height) {
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mx = x + dx[i];
			int my = y + dy[i];
			if (0 <= mx && 0 <= my && mx < N && my < N) {
				if (!visited[my][mx] && map[my][mx] > height) {
					q.push({ mx, my });
					visited[my][mx] = 1;
				}
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] < minh) {
				minh = map[i][j];
			}
			if (map[i][j] > maxh) {
				maxh = map[i][j];
			}
		}
	}
	int cnt = 0, ans = 0;
	for (int k = minh; k <= maxh; k++) {
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && map[i][j] > k) {
					visited[i][j] = 1;
					bfs(j, i, k);
					cnt++;
				}
			}
		}
		if (ans < cnt) {
			ans = cnt;
		}
	}
	cout << ans;
	return 0;
}