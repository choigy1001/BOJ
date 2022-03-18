#include <iostream>
#include <queue>
using namespace std;
int N, K;
int map[100001];
queue <int> q;
int bfs() {
	q.push(N);
	map[N] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (K == x) {
			return map[x] - 1;
		}
		if (x - 1 >= 0 && map[x - 1] == 0) {
			q.push(x - 1);
			map[x - 1] = map[x] + 1;
		}if (x + 1 <= 100000 && map[x + 1] == 0) {
			q.push(x + 1);
			map[x + 1] = map[x] + 1;
		}if (x * 2 <= 100000 && map[x * 2] == 0) {
			q.push(x*2);
			map[x * 2] = map[x] + 1;
		}
	}
}
int main() {
	cin >> N >> K;
	cout << bfs();
	return 0;
}