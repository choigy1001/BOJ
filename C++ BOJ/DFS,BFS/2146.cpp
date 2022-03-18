#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
int N, map[101][101], visited[101][101],cnt,num;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };

void area_name(int a, int b,int name) {
	queue<pair<int, int>> q;
	q.push({ a, b });
	visited[a][b] = 1;
	map[a][b] = name;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mr = r + dr[i];
			int mc = c + dc[i];
			if (0 <= mr && 0 <= mc && mr < N && mc < N) {
				if (!visited[mr][mc] && map[mr][mc]) {
					visited[mr][mc] = 1;
					map[mr][mc] = name;
					q.push({ mr,mc });
				}
			}
		}
	}
}

int bfs(int name) {
	queue<pair<int, int>> q;
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == name) {
				q.push({ i,j });
			}
		}
	}
	
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int mr = r + dr[j];
				int mc = c + dc[j];
				if (0 <= mr && 0 <= mc && mr < N && mc < N) {
					if (map[mr][mc] && map[mr][mc] != name) {
						return count;
					}
					else if (!map[mr][mc] && !visited[mr][mc]) {
						visited[mr][mc] = 1;
						q.push({ mr,mc });
					}
				}
			}
		}
		count++;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !visited[i][j]) {
				area_name(i,j,num++);
			}
		}
	}
	int result = 98765432;

	for (int i = 1; i < num; i++) {
		memset(visited, 0, sizeof(visited));
		result = min(result, bfs(i));
	}
	cout << result;
	return 0;
}