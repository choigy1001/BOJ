#include <iostream>
using namespace std;
int N;
int graph[101][101];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (graph[j][i] && graph[i][k]) {
					graph[j][k] = 1;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}