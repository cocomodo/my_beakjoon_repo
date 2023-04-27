#include <bits/stdc++.h>
using namespace std;

int n;
string board[30];
bool vis[30][30];
int cnt;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

vector<int> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> board[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '0' || vis[i][j] == true) continue;
			cnt++;
			int area = 1;
			queue<pair<int, int>> q;
			vis[i][j] = true;
			q.push({ i,j });
			while (!q.empty()) {
				int x, y;
				tie(x, y) = q.front(); q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] == '0' || vis[nx][ny] == true) continue;
					q.push({ nx,ny });
					vis[nx][ny] = true;
					area++;
				}
			}
			ans.push_back(area);
		}
	}
	cout << cnt<<'\n';
	sort(ans.begin(), ans.end());
	for (auto c : ans) {
		cout << c << '\n';
	}
}