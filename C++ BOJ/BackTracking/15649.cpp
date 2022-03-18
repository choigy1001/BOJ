#include <iostream>

using namespace std;
int N, M;
bool visited[10];
int arr[10];
void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = i;
			dfs(cnt + 1);
			visited[i] = false;
		}

	}
}
int main() {
	cin >> N >> M;

	dfs(0);
	return 0;
}