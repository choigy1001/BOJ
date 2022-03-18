#include <iostream>

using namespace std;
int n, m, s, e;
int dot[500001];
int find(int node) {
	if (dot[node] == node)//�������� �θ� ã������ ��ȯ
		return node;
	else
		return dot[node] = find(dot[node]);
}
bool union_dot(int s, int e) {
	s = find(s);
	e = find(e);
	if (s == e) //�� ����� �θ� ������ ����Ŭ�� �߻�
		return true;
	else {
		dot[s] = e;
		return false;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		dot[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> s >> e;
		if (union_dot(s, e)) {
			ans = i;
			break;
		}
	}
	cout << ans;

	return 0;
}