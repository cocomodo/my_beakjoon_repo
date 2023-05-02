#include <bits/stdc++.h>
using namespace std;

int n;
long long d[105][10];
long long mod = 1'000'000'000;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= 9; i++)
		d[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int k = 0; k <= 9; k++) {
			if (k != 0) d[i][k] += d[i - 1][k - 1];
			if (k != 9) d[i][k] += d[i - 1][k + 1];
			d[i][k] %= mod;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += d[n][i];
	}
	cout << ans % mod;
}