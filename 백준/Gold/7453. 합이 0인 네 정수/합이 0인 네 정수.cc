#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
int a[4'005];
int b[4'005];
int c[4'005];
int d[4'005];
int ab[16'000'005];
ll ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab[cnt++] = a[i] + b[j];
		}
	}
	sort(ab,ab+n*n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			auto ub = upper_bound(ab,ab+n*n, -c[i] - d[j]);
			auto lb = lower_bound(ab,ab+n*n, -c[i] - d[j]);
			int cnt = ub - lb;
			ans += cnt;
		}
	}
	cout << ans;
}