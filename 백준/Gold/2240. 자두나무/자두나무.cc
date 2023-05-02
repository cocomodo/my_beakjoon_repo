#include <bits/stdc++.h>
using namespace std;

int a[1005];
int d[1005][35];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, w;
	cin >> t >> w;
	for (int i = 1; i <= t; i++)
		cin >> a[i];

	//자두가 안움직이고 시간이 지날때의 d[i] 값들을 초기화
	
	int cnt = 0;
	for (int i = 1; i <= t; i++) {
		if (a[i] == 1) cnt++;
		d[i][0] = cnt;
	}
	for (int i = 1; i <= t; i++)
		for (int j = 1; j <= w; j++)
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + (j % 2 + 1 == a[i]);
	
	cout << *max_element(d[t], d[t]+ w + 1);
}