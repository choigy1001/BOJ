#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int build[502], degree[502], alltime[502];
int N, time, before;
queue<int> q;
vector<int> graph[502];
int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> build[i];
		while (1) {
			cin >> before;
			if (before == -1)
				break;
			degree[i]++;
			graph[before].push_back(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			q.push(i);
			alltime[i] = build[i];
		}
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i];
			degree[next]--;

			alltime[next] = max(alltime[next], build[next] + alltime[node]);
			if (degree[next] == 0) {
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << alltime[i] << "\n";
	}

	return 0;
}