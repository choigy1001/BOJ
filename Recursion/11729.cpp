#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int K;
vector<pair<int, int>> v;
void hanoi(int n, int start , int pass, int to) {
	if (n == 1) {
		v.push_back({ start,to });
	}
	else {
		hanoi(n - 1, start, to, pass);
		v.push_back({ start,to });  //last 1
		hanoi(n - 1, pass, start, to);
	}
}
int main() {

	cin >> K;
	hanoi(K,1,2,3);
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}