#include <bits/stdc++.h>
using namespace std;

int n;
int d[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	d[0] = 1;
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = (d[i - 1]%10'007 + d[i - 2]%10'007)%10'007;
	}
	
	cout << d[n];
}