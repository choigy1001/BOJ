#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
int N, M,x,y,from,to;
double ans;
int parent[1001];
vector<pair<int, int>> v, connect,coord;
vector <pair<double, pair<int, int>>> node;
void cal_dist() {
	for (int i = 0; i < N; i++) {
		int x1=coord[i].first;
		int y1 = coord[i].second;
		for (int j = i + 1; j < N; j++) {
			int x2 = coord[j].first;
			int y2 = coord[j].second;
			double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
			node.push_back({ dist,{i + 1, j + 1} });
		}
	}
}
int find(int node) {
	if (parent[node] == node) {
		return node;
	}
	return parent[node] = find(parent[node]);
}
void union_node(int a, int b) {
	a = find(a);
	b = find(b);
	parent[b] = a;
}
bool parent_check(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		coord.push_back({ x,y });
		parent[i+1] = i+1;
	}
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		connect.push_back({ from,to });
	}
	for (int i = 0; i < connect.size(); i++) {
		if (!parent_check(connect[i].first, connect[i].second)) {
			union_node(connect[i].first, connect[i].second);
		}
	}
	cal_dist();
	sort(node.begin(), node.end());
	for (int i = 0; i < node.size(); i++) {
		if (!parent_check(node[i].second.first, node[i].second.second)) {
			union_node(node[i].second.first, node[i].second.second);
			ans += node[i].first;
		}
	}
	//fixed 해야 둘째짜리 고정
	cout << fixed;
	cout.precision(2);
	cout << ans;
	return 0;
}

