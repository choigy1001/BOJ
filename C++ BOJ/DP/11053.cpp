#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,number,ans;
int dp[1001];
vector<int> v;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> number;
		v.push_back(number);
	}
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}