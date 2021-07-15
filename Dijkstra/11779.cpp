#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#define INF 98765432

using namespace std;

typedef pair<int, int> pii;

int n, m, s, e, w,A,B;
int dist[1001],trace[1001];
vector<pii> v[100001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> trace_v;
void dijkstra(int start, int end) {
	dist[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		//«ÿ¡‡æﬂ Ω√∞£√ ∞˙ æ»∂‰
		if (dist[cur] < cost) {
			continue;
		}
		for (int i = 0; i<v[cur].size(); i++) {
			int nextcur = v[cur][i].first;
			int nextcost = v[cur][i].second;
			
			if (dist[nextcur] > dist[cur] + nextcost){
				trace[nextcur] = cur;
				dist[nextcur] = dist[cur] + nextcost;
				pq.push({ dist[nextcur],nextcur });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> s >> e >> w;
		v[s].push_back({e,w});
	}
	cin >> A >> B;

	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dijkstra(A,B);
	cout << dist[B]<<"\n";
	int temp = B;
	while (temp) {
		trace_v.push_back(temp);
		temp = trace[temp]; //Ω√¿€¡° dist=0 ¿Ãπ«∑Œ ∏ÿ√„
	}
	cout << trace_v.size() << "\n";

	for (int i = trace_v.size() - 1; i >= 0; i--) {
		cout << trace_v[i] << " ";
	}
	return 0;
}