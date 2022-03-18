#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
int T, F;
string name1, name2;
//�̸��� �� �ٸ� ��� 100000*2�� MAX
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
			swap(node1, node2); //����� ū�ɷ� ����
		}
		parent[node2] = node1; //node2 ����  -> node1 ���տ� ��ħ
		set_size[node1] += set_size[node2]; //node1 ���� ������ ����
		set_size[node2] = 0; //���������� node2 ������� 0
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