#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<double, double> pdd;
int n;
double x,y, dist_sum;
vector <pdd> v;
vector<pair<double, pair<int, int>>> edge;
int parent[101];
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
	if (node1 == node2)
		return true;
	return false;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			double tempx=(v[i].first - v[j].first)* (v[i].first - v[j].first);
			double tempy = (v[i].second - v[j].second) * (v[i].second - v[j].second);
			double dist=sqrt(tempx + tempy);
			edge.push_back({ dist, { i,j } });
		}
	}
	//����� �����ͺ��� �����ϱ� ���� ����
	sort(edge.begin(), edge.end());
	for (int i = 0; i < edge.size(); i++) {
		if (!sameparent(edge[i].second.first, edge[i].second.second)) { //�θ� ������ ����Ŭ �߻�
			union_node(edge[i].second.first, edge[i].second.second);
			dist_sum += edge[i].first;
		}
	}
	//�Ҽ��� ���� ��°�ڸ�����
	cout << fixed;
	cout.precision(2);

	cout << dist_sum;
	return 0;
}