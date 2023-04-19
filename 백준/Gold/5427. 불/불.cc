#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int TC, bX, bY;
int board[1002][1002];
int visF[1002][1002];
int visS[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	while (TC--) {
		bool escape = false;
		queue<pair<int, int>> Qf, Qs;
		cin >> bY >> bX;
		for (int i = 0; i < bX; i++) {
			fill(visF[i], visF[i] + bY, 0);
			fill(visS[i], visS[i] + bY, 0);
		}
		for (int i = 0; i < bX; i++) {
			for (int j = 0; j < bY; j++) {
				char c;
				cin >> c;
				if (c == '#') board[i][j] = -1;
				else {
					if (c == '@') {
						Qs.push({ i,j });
						visS[i][j] = 1;
					}
					else if (c == '*') {
						Qf.push({ i,j });
						visF[i][j] = 1;
					}
					board[i][j] = 0;//벽이 아닌 나머지는 다 0으로 받기 위해 이렇게
					//작성하는것 같은데. 
				}
			}
			
		}
		while (!Qf.empty()) {
			auto v = Qf.front(); Qf.pop();
			for (int k = 0; k < 4; k++) {
				int nx = v.X + dx[k];
				int ny = v.Y + dy[k];
				if (nx < 0 || nx >= bX || ny < 0 || ny >= bY) continue;
				if (board[nx][ny] == -1 || visF[nx][ny]) continue;//벽이거나 들렀거나.
				visF[nx][ny] = visF[v.X][v.Y] + 1;
				Qf.push({ nx,ny });
			}
		}
		while (!Qs.empty() && !escape) {
			auto v = Qs.front(); Qs.pop();
			for (int k = 0; k < 4; k++) {
				int nx = v.X + dx[k];
				int ny = v.Y + dy[k];
				if (nx < 0 || nx >= bX || ny < 0 || ny >= bY) {
					cout << visS[v.X][v.Y] << "\n";
					escape = true;
					break;
				}
				if (board[nx][ny] == -1) continue;//벽이면 패스
				if (visS[nx][ny]) continue;
				//visF[nx][ny]==0이면 전역변수라 기본이 0이라 도달하지 못한 벽이라는 의미
				//visF[nx][ny]<=visS[v.X][v.Y]+1 라고 하는 이유는, 
				//visF[nx][ny]는 이미 쓰여있는 값이고, visS[v.X][v.Y]는 한차수 적을때의 값,
				//거기에 +1을 해서 아직 어디다가 쓰지는 않았지만 써주어야 할 값에 해당하는
				//visS[v.X][v.Y]+1의 값과 같거나 상근이쪽이 더 클때 라는 의미이고
				//그건 상근이가 거기 도달하면 불과 같이 도착하거나 더 늦었다는 의미이다. 
				//visF[nx][ny]에 쓰여진 값과, visS[v.X][v.Y]+1로 쓰여야 하는 값에 대해서
				//이해를 잘 해야한다. 
				if (visF[nx][ny] != 0 && visF[nx][ny] <= visS[v.X][v.Y] + 1) continue;
				visS[nx][ny] = visS[v.X][v.Y] + 1;
				Qs.push({ nx,ny });
			}
		}
		if (!escape) cout << "IMPOSSIBLE" << "\n";
	}
}