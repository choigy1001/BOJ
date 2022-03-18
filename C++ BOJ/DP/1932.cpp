#include <iostream>
#include <algorithm>

using namespace std;
int n, ta[501][501], dp[501][501];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> ta[i][j];
		}
	}
	dp[1][1] = ta[1][1];
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			if (dp[i + 1][j] < dp[i][j] + ta[i + 1][j]) {
				dp[i + 1][j] = dp[i][j] + ta[i + 1][j];
			}
			if (dp[i + 1][j + 1] < dp[i][j] + ta[i + 1][j + 1]) {
				dp[i + 1][j + 1] = dp[i][j] + ta[i + 1][j + 1];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}