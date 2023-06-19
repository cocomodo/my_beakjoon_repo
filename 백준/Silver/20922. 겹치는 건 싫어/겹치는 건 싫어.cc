#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
int a[200'005];
int cnt[100'005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	int en = 0;
	cnt[a[en]]++;
	for (int st = 0; st < n; st++) {
		/*추가할 수 있는지 확인하기 위해서 <k 를 확인
		<=k로 작성하면, ==k일때 추가를 못하니까 <k로 확인*/
		while (en + 1 != n && cnt[a[en + 1]] < k) {
			en++;
			cnt[a[en]]++;
		}
		ans = max(ans, en - st + 1);/*en + 1 == n이거나,
		cnt[a[en+1]]==k가 된 경우(이미 k라 체크를 더 못하는 경우의 원소) 이 말은 즉 2개 나와야 하면 이미 다음 원소가 그 원소라
		지금 원소를 추가를 못시킨다는 상황*/
		cnt[a[st]]--;
	}
	cout << ans;
}