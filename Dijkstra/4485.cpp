#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <cstring>
#define INF 5000000
using namespace std;
int N;
int cave[126][126];
int dist[126][126];
int visited[126][126];
typedef pair<int, int> pii;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt = 1;
	while (1) {
		cin >> N;
		if (N == 0)
			break;
		priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>>pq;
		memset(cave, 0, sizeof(cave));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> cave[i][j];
				dist[i][j] = INF;
			}
		}
		dist[0][0] = cave[0][0];
		pq.push({ 0,pii(0, 0) });
		visited[0][0] = 1;
		while (!pq.empty()) {
			int y = pq.top().second.first;
			int x = pq.top().second.second;
			int d = pq.top().first;
			pq.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				int nd = d + cave[ny][nx];
				if (0 <= nx && 0 <= ny && nx < N && ny < N) {
					if (!visited[ny][nx] && dist[ny][nx] > nd) {
						visited[ny][nx] = 1;
						dist[ny][nx] = nd;
						pq.push({ nd, pii(ny,nx) });
					}
				}
			}

		}
		cout << "Problem " << cnt++ << ": " << cave[0][0] + dist[N - 1][N - 1] << "\n";
	}
	return 0;
}