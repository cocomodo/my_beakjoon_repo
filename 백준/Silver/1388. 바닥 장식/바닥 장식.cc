#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[60];
bool vis[60][60];
int ans;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j]) continue;
			ans++;
			vis[i][j] = true;
			char shape = board[i][j];
			if (shape == '-') {
				for (int k = j + 1; k < m; k++) {
					if (board[i][k] == '|') break;
					vis[i][k] = true;
				}
			}
			else {
				for (int k = i + 1; k < n; k++) {
					if (board[k][j] == '-') break;
					vis[k][j] = true;
				}
			}
		}
	}
	cout << ans;
}