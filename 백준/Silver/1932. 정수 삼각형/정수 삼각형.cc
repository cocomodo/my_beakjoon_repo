#include <bits/stdc++.h>
using namespace std;

int n;
int d[505][505];
int p[505][505];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> d[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			p[i][j] = max(p[i - 1][j - 1], p[i - 1][j]) + d[i][j];
	cout << *max_element(p[n] + 1, p[n] + 1 + n);
}