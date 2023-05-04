#include <bits/stdc++.h>
using namespace std;

int n;
long long board[105][105];
long long d[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	d[1][1] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			
			int jump = board[i][j];
			if (i != n && i + jump)
				d[i + jump][j] = d[i + jump][j] + d[i][j];
			if (j != n && j + jump)
				d[i][j + jump] = d[i][j + jump] + d[i][j];
		}
	}
	cout << d[n][n];
}