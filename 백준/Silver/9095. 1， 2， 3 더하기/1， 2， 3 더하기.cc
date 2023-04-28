#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int d[15];
// n= 1~10
int main() {
	ios::sync_with_stdio(0);
	cin >> t;

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 4; i <= 10; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}
	while (t--) {
		cin >> n;
		cout << d[n] << '\n';
	}
}