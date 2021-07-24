#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L, C;
char word[16];
bool check[16];
vector <char> v;
void dfs(int index, int cnt) {
	if (cnt == L) {//모음 자음 테스트
		int vowel = 0, consonant = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 'a' || v[i] == 'e' || v[i] == 'o' || v[i] == 'i' || v[i] == 'u') {
				vowel++;
			}
			else {
				consonant++;
			}
		}
		if (vowel >= 1 && consonant >= 2) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
			}
			cout << "\n";
			return;
		}
		else {
			return;
		}
	}

	for (int i = index; i < C; i++) {
		if (!check[i]) {
			check[i] = true;
			v.push_back(word[i]);
			dfs(i + 1, cnt + 1);
			check[i] = false;
			v.pop_back();
		}
	}

}
int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> word[i];
	}
	sort(word, word + C);

	dfs(0, 0);

	return 0;
}