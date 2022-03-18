#include <iostream>
#include <algorithm>
using namespace std;
int N, k,low,high,ans,cnt;
int main() {
	cin >> N >> k;
	low = 1, high = k;
	while (low <= high) {
		cnt = 0;
		int mid = (low + high) / 2;
		for (int i = 1; i <= N; i++) {
			cnt += min(N, mid / i);
		}
		if (cnt < k) {
			low = mid + 1;
		}
		else {
			ans = mid;
			high = mid - 1;
		}
	}
	cout << ans;
	return 0;
}