#include <iostream>
#include <utility>
#include <queue>

using namespace std;
int M, N, H, cnt;
int box[101][101][101];
bool visited[101][101][101];
queue<pair<pair<int, int>, int>> q;
int dr[] = { 1,-1,0,0,0,0 };
int dc[] = { 0,0,1,-1,0,0 };
int dh[] = { 0,0,0,0,1,-1 };
bool tomato_check() {
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (box[i][j][k] == 0) {
					return false;
				}
			}
		}
	}
	return true;
}
void bfs() {
	//1이 없는경우 진행 할수 없으므로 -1
	if (q.empty()) {
		cout << "-1";
		return;
	}
	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int r = q.front().first.first;
			int c = q.front().first.second;
			int h = q.front().second;
			q.pop();
			for (int j = 0; j < 6; j++) {
				int mr = r + dr[j];
				int mc = c + dc[j];
				int mh = h + dh[j];
				if (0 <= mr && 0 <= mc && 0 <= mh && mr < N && mc < M && mh < H) {
					if (box[mr][mc][mh] == 0) {
						box[mr][mc][mh] = 1;
						q.push({ {mr,mc},mh });
					}
				}
			}
			if (q.size() == 0 && tomato_check()) {
				cout << cnt;
				return;
			}
			else if (q.size() == 0 && !tomato_check()) {
				cout << "-1";
				return;
			}
		}
		cnt++;
	}
}
int main() {
	cin >> M >> N >> H;
	bool allripe = true;
	int notomato = 0;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					q.push({ {i,j},k });
				}
				if (box[i][j][k] == 0) {
					allripe = false;
				}
			}
		}
	}

	if (allripe == true) {
		cout << "0";
	}
	else {
		bfs();
	}
	return 0;
}