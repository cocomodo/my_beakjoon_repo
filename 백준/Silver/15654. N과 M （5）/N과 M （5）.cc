#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];
int arr2[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr2[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			isused[i] = 1;
			arr2[k] = arr[i];
			func(k + 1);
			isused[i] = 0;
		}
	}
	return;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	func(0);
	return 0;
}