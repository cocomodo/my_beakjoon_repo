#include <bits/stdc++.h>
using namespace std;

int t;
int a[3][100'005];
int d[3][100'005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];

		d[1][0] = 0;
		d[2][0] = 0;
		d[1][1] = a[1][1];
		d[2][1] = a[2][1];
	
		for (int j = 2; j <= n; j++) {
			d[1][j] = max(d[2][j - 2], d[2][j - 1]) + a[1][j];
			d[2][j] = max(d[1][j - 2], d[1][j - 1]) + a[2][j];
		}
		cout << max(d[1][n], d[2][n]) << '\n';
	}
}