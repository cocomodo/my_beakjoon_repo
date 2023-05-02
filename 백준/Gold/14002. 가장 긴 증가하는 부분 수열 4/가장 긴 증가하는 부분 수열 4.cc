#include <bits/stdc++.h>
using namespace std;

int a[1005];
int d[1005];
int pre[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	fill(d + 1, d + 1 + n, 1);//d[0]을 아래부분에서 접근하는지 고려해보자.
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				pre[i] = j;
			}
		}
	}
	int maxI = 1;
	int maxD = d[1];
	for (int i = 2; i <= n; i++) {
		if (maxD < d[i]) {
			maxI = i;
			maxD = d[i];
		}
	}
	deque<int> ans;
	int cur = maxI;
	while (cur) {
		ans.push_front(a[cur]);
		cur = pre[cur];
	}
	cout << ans.size() << '\n';
	for (auto c : ans)
		cout << c << ' ';
}