#include <bits/stdc++.h>
using namespace std;

int L, C;
int arr[20];
char s[20];

bool aeiou(char t) {
	return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}


void func(int k, int st) {
	if (k == L) {
		bool flag = false;
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = 0; i < L; i++) {
			if (aeiou(s[arr[i]])) cnt1++;
			else cnt2++;
		}
		if (cnt1 >=1 && cnt2 >= 2) flag = true;

		if (flag) {
			for (int i = 0; i < L; i++)
				cout << s[arr[i]];
			cout << '\n';
		}
	}
	for (int i = st; i < C; i++) {
		arr[k] = i;
		func(k + 1, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> L >> C;
	for (int i = 0; i < C; i++) cin >> s[i];
	sort(s, s + C);
	func(0, 0);
}