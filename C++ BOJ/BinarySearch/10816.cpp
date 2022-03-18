#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, number;
vector<int> total,v;
int low(int search) {
	int start = 0, end = N - 1;
	while (end>start) {
		int mid = (start + end) / 2;
		if (total[mid] >= search) {
			end = mid;
			
		}
		else {
			start = mid + 1;
		}
	}
	return end;
}
int high(int search) {
	int start = 0, end = N - 1;
	while (end > start) {
		int mid = (start + end) / 2;
		if (total[mid] > search) {
			end = mid;

		}
		else {
			start = mid + 1;
		}
	}
	return end;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> number;
		total.push_back(number);
	}
	cin >> M;
	sort(total.begin(), total.end());
	for (int i = 0; i < M; i++) {
		cin >> number;
		v.push_back(number);
		//cout << upper_bound(total.begin(), total.end(), number)-lower_bound(total.begin(),total.end(), number) << " ";
	}
	for (int i = 0; i < M; i++) {
		int low_index = low(v[i]);
		int high_index = high(v[i]);
		if (high_index == N - 1 && total[N - 1] == v[i]) {
			high_index++;
		}
		cout << high_index - low_index<<" ";
	}
	return 0;
}