#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int N, M, X, from, to, weight, dist[1005], ans[1005];
vector<pii> v[1001];

void dijkstra(int start) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			
			int next = v[cur][i].first;
			int nextcost = v[cur][i].second;

			if (dist[next] > cost + nextcost) {
				dist[next] = cost + nextcost;
				pq.push({ dist[next],next });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		cin >> from >> to >> weight;
		v[from].push_back({ to,weight });
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[j] = 999999;
		}
		dijkstra(i);
		ans[i] = dist[X];
	}
	for (int i = 1; i <= N; i++) {
		dist[i] = 999999;
	}
	dijkstra(X);
	for (int i = 1; i <= N; i++) {
		ans[i] += dist[i];
	}
	sort(ans + 1, ans + N + 1);
	cout << ans[N];

	return 0;
}