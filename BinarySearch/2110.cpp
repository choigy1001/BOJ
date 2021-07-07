#include <iostream>
#include <algorithm>
using namespace std;
int N, C,ans;
int home[200001];

bool check(int distance) {
	int cnt = 1;
	int before = home[0];
	for (int i = 1; i < N; i++) {
		if (home[i] - before>=distance) {
			before = home[i];
			cnt++;
		}
	}
	if (cnt >= C) {
		return true;
	}
	return false;
}
int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> home[i];
	}
	sort(home, home + N);
	int low = 1, high = home[N-1] - home[0];
	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(mid)) {
			low = mid + 1;
			ans = max(ans, mid);
		}
		else {
			high = mid - 1;
		}
	}
	cout << ans;
	return 0;
}