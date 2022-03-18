#include <iostream>
#include <cstring>
using namespace std;
int G, P,num,cnt;
int parent[100001];

int find(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}

int main() {
	cin >> G >> P;
	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < P; i++) {
		cin >> num;
		if (find(num)) {
			cnt++;
			parent[find(num)] = find(find(num) - 1);
		}
		else if (!find(num)) {
			break;
		}
	}
	cout << cnt;
	return 0;
}