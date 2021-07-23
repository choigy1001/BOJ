#include <iostream>
#include <vector>
#include <queue>

using namespace std;
char map[51][51];
bool visited[51][51];
int R, C, cnt;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };
queue <pair<int, int>> river, animal;

void bfs() {
	while (!animal.empty()) {
		int rsize = river.size();
		for (int i = 0; i < rsize; i++) {
			int r = river.front().first;
			int c = river.front().second;
			river.pop();
			for (int j = 0; j < 4; j++) {
				int mr = r + dr[j];
				int mc = c + dc[j];
				if (0 <= mr && 0 <= mc && mr < R && mc < C ) {
					if (map[mr][mc] != 'X' && map[mr][mc]!='*' &&map[mr][mc]!='D') { //*을 확인해서 재방문안하도록 방지
						river.push({ mr,mc });
						map[mr][mc] = '*';
					}
				}
			}
		}
		int asize = animal.size();
		for (int i = 0; i < asize; i++) {
			int ar = animal.front().first;
			int ac = animal.front().second;
			animal.pop();
			for (int j = 0; j < 4; j++) {
				int amr = ar + dr[j];
				int amc = ac + dc[j];
				if (0 <= amr && 0 <= amc && amr < R && amc < C) {
					if (map[amr][amc] != 'X' && map[amr][amc] != '*' && !visited[amr][amc]) {//방문표시를 해줘야 메모리 초과 안남
						if (map[amr][amc] == 'D') {
							cout << cnt + 1;
							return;
						}
						visited[amr][amc] = true;
						animal.push({ amr,amc });
					}
				}
			}
		}
		cnt++;
	}
	cout << "KAKTUS";
}
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') {
				river.push({ i,j });
			}
			if (map[i][j] == 'S') {
				animal.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}
	bfs();
	
	return 0;
}