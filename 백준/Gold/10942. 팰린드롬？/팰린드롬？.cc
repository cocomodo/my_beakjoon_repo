#include <bits/stdc++.h>
using namespace std;

int a[2005];
int d[2005][2005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		d[i][i] = 1;
		if (a[i - 1] == a[i]) d[i - 1][i] = 1;
	}
	for (int gap = 2; gap < n; gap++) {
		for (int i = 1; i <= n; i++) {
			int s = i;
			int e = i + gap;
			if (a[s] == a[e] && d[s + 1][e - 1]) d[s][e] = 1;
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int s;
		int e;
		cin >> s >> e;
		cout << d[s][e] << '\n';
	}
}