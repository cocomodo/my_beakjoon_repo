#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
int a[4'005];
int b[4'005];
int c[4'005];
int d[4'005];
vector<int> sums;
ll ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sums.push_back(a[i] + b[j]);
		}
	}
	sort(sums.begin(), sums.end());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			auto ub = upper_bound(sums.begin(), sums.end(), -c[i] - d[j]);
			auto lb = lower_bound(sums.begin(), sums.end(), -c[i] - d[j]);
			int cnt = ub - lb;
			ans += cnt;
		}
	}
	cout << ans;
}