#include <iostream>

using namespace std;
int N, white, blue;
int map[128][128];
void quad(int y, int x, int N) {
	int check = map[y][x];

	for (int i = y; i < y + N; i++) {
		for (int j = x; j < x + N; j++) {

			if (check == 0 && map[i][j] == 1) {
				check = 2;
			}
			if (check == 1 && map[i][j] == 0) {
				check = 2;
			}
			if (check == 2) {

				quad(y, x, N / 2);
				quad(y, x + N / 2, N / 2);
				quad(y + N / 2, x, N / 2);
				quad(y + N / 2, x + N / 2, N / 2);
				return;
			}
		}
	}
	if (check == 0)
		white++;
	else
		blue++;

}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	quad(0, 0, N);
	cout << white << "\n" << blue;
	return 0;
}
