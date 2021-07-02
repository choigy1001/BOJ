#include <iostream>
#include <algorithm>
using namespace std;
int N, ans;
int time[16], cost[16];
void dfs(int nowday, int nowsum, int add_cost) {//현재 날짜, 현재 합친것, 더하는 값
	if (nowday == N + 1) {//N+1에 딱 퇴사할수있게 된다 만약 N=7 7일에 1일 걸리는 일 있으면 끝나는게 예시
		ans = max(ans, nowsum);
		return;
	}
	else if (nowday > N + 1) {//오바할시 마지막 상담은 진행 못하므로 add_cost 빼준다
		ans = max(ans, nowsum - add_cost);
		return;
	}
	for (int i = nowday + time[nowday]; i <= N + time[nowday]; i++) {
		dfs(i, nowsum + cost[nowday], cost[nowday]);
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> time[i] >> cost[i];
	}
	for (int i = 1; i <= N; i++) {
		dfs(i, 0, 0);
	}
	cout << ans;
	return 0;
}