#include <bits/stdc++.h>
using namespace std;

int a[100'005];
int d[100'005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	d[1] = a[1];
	for (int i = 2; i <= n; i++)
		d[i] = d[i - 1] + a[i];
	while(m--) {
		int a, b;
		cin >> a >> b;
		cout << d[b] - d[a - 1] << '\n';
	}
}