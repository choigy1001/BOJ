#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int lli;
lli K, N,maxlen, cnt;
int len[10001],high;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> len[i];
		high = max(len[i], high);
	}
	lli low = 1; //0으로 할시 divide 0 에러
	while (low <= high) {
		cnt = 0;
		lli mid = (low + high) / 2;
		for (int i = 0; i < K; i++) {
			cnt += (len[i] / mid);
		}
		if (cnt>=N) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << high;

	return 0;
}