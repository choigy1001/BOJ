#include <iostream>

using namespace std;
int n, dp[1002];
int main() {
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {//오버플로우 발생해서 먼저 계산한다
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	}

	cout << dp[n];

	return 0;
}