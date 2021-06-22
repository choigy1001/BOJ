#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> pii;
vector <pii> v;
int N, time, sum, wait;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> time;
		v.push_back({time, i});
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		sum = 0;
		for (int j = 0; j < N; j++) {
			if (i < j)
				break;
			sum += v[j].first;
		}
		wait += sum;
	}
	cout << wait;
	return 0;
}