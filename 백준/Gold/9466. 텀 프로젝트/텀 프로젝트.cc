#include <bits/stdc++.h>
using namespace std;

int arr[100'005];
int n;
int state[100'005];

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x) {
	int cur = x;
	while (true) {
		state[cur] = x;
		cur = arr[cur];
		//이번 방문에서 지나간 학생에 도달했을 경우
		if (state[cur] == x) {
			while (state[cur] != CYCLE_IN) {
				state[cur] = CYCLE_IN;
				cur = arr[cur];
			}
			return;
		}
		//이정 방문에서 지나간 학생에 도달했을 경우
		else if (state[cur] != 0) return;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		fill(state + 1, state + 1 + n, 0);
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		//int ans = 0; 
		for (int i = 1; i <= n; i++) {
			if (state[i] == NOT_VISITED) run(i);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (state[i] != CYCLE_IN) cnt++;
		}
		cout << cnt << "\n";
	}
}