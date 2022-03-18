#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, S,ans,setcnt;
int set[21];
bool check[21];
vector<int> v;
void dfs(int select, int cnt, int size) {
	if (cnt == size) {
		ans = 0;
		for (int i = 0; i < v.size(); i++) {
			ans += v[i];
		}
		if (ans==S) {
			setcnt++;
		}
		return;
	}
	else {
		for (int i = select; i < N; i++) {
			if (check[i]) {
				continue;
			}
			check[i] = true;
			v.push_back(set[i]);
			dfs(i, cnt + 1, size);
			check[i] = false;
			v.pop_back();
		}
		
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> set[i];
	}
	for (int i = 1; i <= N; i++) {
		dfs(0, 0, i);
	}
	cout << setcnt;
	return 0;
}