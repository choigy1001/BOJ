#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int set[13], check[13];
int number;
int num = 6;
vector<int> v;
void dfs(int select, int cnt) {
	if (cnt == num) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = select; i < number; i++) {
			if (check[i] == true) {
				continue;
			}
			check[i] = true;
			v.push_back(set[i]);
			dfs(i, cnt + 1);
			check[i] = false;
			v.pop_back();
		}

	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		cin >> number;
		if (number == 0) {
			break;
		}

		for (int i = 0; i < number; i++) {
			cin >> set[i];
		}
		dfs(0, 0);
		cout << "\n";
		memset(set, 0, sizeof(set));
		memset(check, 0, sizeof(check));
		v.clear();
	}

	return 0;
}