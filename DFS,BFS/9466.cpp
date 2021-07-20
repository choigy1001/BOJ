#include <iostream>
#include <cstring>

using namespace std;
int T, n, target, cnt;
int student[100001], visited[100001], selected[100001];
void dfs(int node) {
	visited[node] = true;
	if (!visited[student[node]]) {
		dfs(student[node]);
	}
	else if (!selected[student[node]]) {
		for (int i = student[node]; i != node; i = student[i]) {
			cnt++;
		}
		cnt++;
	}
	selected[node] = 1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> student[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		cout << n - cnt<<"\n";
		memset(student, 0, sizeof(student));
		memset(visited, 0, sizeof(visited));
		memset(selected, 0, sizeof(selected));
		cnt = 0;
	}
	
	return 0;
}