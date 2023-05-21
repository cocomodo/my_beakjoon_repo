#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0);
	
	int n, c;
	cin >> n >> c;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		bool chk = false;
		for (auto& a : v) {
			if (a.second == t) {
				a.first++;
				chk = true;
				break;
			}
		}
		if (chk == false) v.push_back({ 1,t });
	}
	stable_sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.first > b.first;
	});
	for (auto b : v) {
		while (b.first--) cout << b.second << ' ';
	}
}