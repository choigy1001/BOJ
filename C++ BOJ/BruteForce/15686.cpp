#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int ans = 9999999;
int map[51][51];
bool check[13];
typedef pair<int, int> pii;
vector <pii> house, chicken, v;

int calculate_dist() {
	int tempdist = 0;
	for (int i = 0; i < house.size(); i++) {
		int dist = 9999999;
		for (int j = 0; j < v.size(); j++) {
			dist = min(dist, abs(house[i].first - v[j].first) + abs(house[i].second - v[j].second));
		}
		tempdist += dist;
	}
	return tempdist;
}

void dfs(int index, int cnt) {//start point , choose count
	if (cnt == M) { //chicken selected=M
		ans = min(ans, calculate_dist());
		return; //14,15 prevent
	}
	for (int i = index; i < chicken.size(); i++) {
		if (check[i]) {
			continue;
		}
		check[i] = true;
		v.push_back(chicken[i]);
		dfs(i, cnt + 1);
		check[i] = false;
		v.pop_back();
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				house.push_back({ i,j });
			}
			else if (map[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}
	dfs(0, 0);

	cout << ans;
	return 0;
}