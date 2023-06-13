#include <bits/stdc++.h>
using namespace std;

int n,c;
int a[200'005];
int ans;

bool possible(int len) {
	int cnt = 1;
	int prev = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] - prev >= len) {
			prev = a[i];
			cnt++;
		}
	}
	if (cnt >= c) return true;
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int low = 1;
	int high = a[n - 1] - a[0];
	while (low <= high) {
		int mid = (low + high) / 2;
		if (possible(mid)) {
			ans = max(ans, mid);
			low = mid + 1;
		}
		else high = mid - 1;
	}
	cout << ans;
}