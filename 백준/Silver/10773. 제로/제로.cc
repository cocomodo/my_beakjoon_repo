#include <bits/stdc++.h>
using namespace std;

stack<int> S;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		int m;
		cin >> m;
		if (m != 0) {
			S.push(m);
			ans += m;
		}
		else {
			ans -= S.top();
			S.pop();
		}
	}
	cout << ans;
}