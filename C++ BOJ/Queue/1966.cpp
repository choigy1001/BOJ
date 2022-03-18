#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
int t, N, M, order, cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		queue<pii> q;
		priority_queue<int> pq;
		cnt = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> order;
			q.push({ i, order });
			pq.push(order);
		}

		while (!q.empty()) {
			int nindex = q.front().first;
			int norder = q.front().second;
			q.pop();
			if (norder == pq.top()) {
				pq.pop();
				cnt++;
				if (nindex == M) {
					cout << cnt << "\n";
					break;
				}
			}
			else {
				q.push({ nindex, norder });
			}
		}
	}
	return 0;
}