#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, int> pii;
int t, m, n, x, y, z, total, dist_sum;
int parent[200002];
int find(int node) {
	if (parent[node] == node) {
		return node;
	}
	return parent[node] = find(parent[node]);
}
void union_node(int node1, int node2) {
	node1 = find(node1);
	node2 = find(node2);

	if (node1 != node2) {
		parent[node1] = node2;
	}
}
bool sameparent(int node1, int node2) {
	node1 = find(node1);
	node2 = find(node2);

	if (node1 != node2) {
		return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		vector <pair<int, pii>> v;
		total=0, dist_sum = 0;
		cin >> m >> n;
		if (m == 0 && n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;

			v.push_back({ z, {x,y} });
			total += z;
		}

		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			if (!sameparent(v[i].second.first, v[i].second.second)) {
				union_node(v[i].second.first, v[i].second.second);
				dist_sum += v[i].first;
			}
		}
		cout << total - dist_sum << "\n";
	}
	return 0;
}