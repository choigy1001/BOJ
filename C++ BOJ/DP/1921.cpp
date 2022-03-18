#include <iostream>
#include <algorithm>
using namespace std;
int num[100001],dp[100001], ans;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	dp[0] = num[0];
	ans = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + num[i], num[i]);
		ans = max(dp[i], ans);
	}
	cout << ans;
	return 0;
}