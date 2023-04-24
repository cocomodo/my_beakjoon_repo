#include <bits/stdc++.h>
using namespace std;

int n, s;
int nums[25];
int cnt;

void func(int idx, int sum) {
	if (idx == n) {
		if (sum == s) {
			cnt++;
		}
		return;
	}
	func(idx + 1, sum + nums[idx]);
	func(idx + 1, sum);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	func(0, 0);
	if (s == 0) {
		cnt--;
	}
	cout << cnt << "\n";
}