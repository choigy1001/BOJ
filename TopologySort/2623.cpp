#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M,num,order,cur;
int degree[1001];
vector<int> v[1001],result;
queue<int> q;

int main() {

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> num >> cur;
		for (int j = 1; j < num; j++) {
			cin >> order;
			v[cur].push_back(order);
			degree[order]++;
			cur = order;

		}
	}
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}
	int index = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		result.push_back(node);
		for (int i = 0; i < v[node].size(); i++) {
			int nextnode = v[node][i];
			degree[nextnode]--;

			if (degree[nextnode] == 0) {
				q.push(nextnode);
			}
		}
	}
	if (!result.size()==N) {
		cout << "0";
	}
	for (int i = 0; i < N; i++) {
		cout << result[i] << "\n";
	}
	return 0;

}