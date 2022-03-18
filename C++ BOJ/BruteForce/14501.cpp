#include <iostream>
#include <algorithm>
using namespace std;
int N, ans;
int time[16], cost[16];
void dfs(int nowday, int nowsum, int add_cost) {//���� ��¥, ���� ��ģ��, ���ϴ� ��
	if (nowday == N + 1) {//N+1�� �� ����Ҽ��ְ� �ȴ� ���� N=7 7�Ͽ� 1�� �ɸ��� �� ������ �����°� ����
		ans = max(ans, nowsum);
		return;
	}
	else if (nowday > N + 1) {//�����ҽ� ������ ����� ���� ���ϹǷ� add_cost ���ش�
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