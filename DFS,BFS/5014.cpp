#include <iostream>
#include <queue>
using namespace std;
int F, S, G, U, D, floors[1000001];
queue<int> q;
int bfs(int start) {
	q.push(start);
	floors[start] = 1;
	while (!q.empty()) {
		int curfloor = q.front();
		if (curfloor == G) {
			return 1;
		}
		q.pop();		
		int df[2] = {  U, -D };
		for (int i = 0; i < 2; i++) {
			int mf = curfloor + df[i];
			if (1 <= mf && mf <= F && !floors[mf]) {
				floors[mf] = floors[curfloor]+1;
				q.push(mf);
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> F >> S >> G >> U >> D;
	
	if (bfs(S) == 1) {
		cout << floors[G] - 1;
	}
	else {
		cout << "use the stairs";
	}	
	return 0;
}