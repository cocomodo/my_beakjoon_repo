#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[60];
bool vis[60][60];

int dx[2] = { 1,-1 };
int dy[2] = { 1,-1 };
int cnt;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == true) continue;
			if (board[i][j] == '-') {
				queue<pair<int, int>> q;
				q.push({ i,j });
				vis[i][j] = true;
				cnt++;
				while (!q.empty()) {
					int x, y;
					tie(x, y) = q.front(); q.pop();
					for (int k = 0; k < 2; k++) {
						int nx = x;
						int ny = y + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] == '|' || vis[nx][ny] == true) continue;
						q.push({ nx,ny });
						vis[nx][ny] = true;
					}
				}
			}
			else {//board[i][j]=='|'일때
				queue<pair<int, int>> q;
				q.push({ i,j });
				vis[i][j] = true;
				cnt++;
				while (!q.empty()) {
					int x, y;
					tie(x, y) = q.front(); q.pop();
					for (int k = 0; k < 2; k++) {
						int nx = x+dx[k];
						int ny = y ;
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] == '-' || vis[nx][ny] == true) continue;
						q.push({ nx,ny });
						vis[nx][ny] = true;
					}
				}
			}
		}
	}
	cout << cnt;
}