#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
int T, F;
string name1, name2;
//이름이 다 다를 경우 100000*2가 MAX
int parent[200001], set_size[200001];

int find(int node) {
	if (node == parent[node]) {
		return node;
	}
	return parent[node] = find(parent[node]);
}
void union_node(int node1, int node2) {
	node1 = find(node1);
	node2 = find(node2);

	if (node1 != node2) {
		if (set_size[node1] < set_size[node2]) {
			swap(node1, node2); //사이즈가 큰걸로 변경
		}
		parent[node2] = node1; //node2 집합  -> node1 집합에 합침
		set_size[node1] += set_size[node2]; //node1 집합 사이즈 증가
		set_size[node2] = 0; //병합함으로 node2 사이즈는 0
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;

	while (T--) {
		map<string, int> name;
		int index = 1;
		for (int i = 0; i < 200001; i++) {
			parent[i] = i;
			set_size[i] = 1;
		}
		
		cin >> F;
		
		for (int i = 0; i < F; i++) {
			cin >> name1 >> name2;
			if (!name.count(name1)) {
				name[name1] = index++;
			}
			if (!name.count(name2)) {
				name[name2] = index++;
			}

			int parent1 = find(name[name1]);
			int parent2 = find(name[name2]);

			if (parent1 == parent2) {
				cout << max(set_size[parent1], set_size[parent2]) << "\n";
			}
			else {
				union_node(parent1, parent2);
				cout << max(set_size[parent1], set_size[parent2]) << "\n";
			}
		}
	}
	return 0;
}