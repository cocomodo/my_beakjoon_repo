#include <bits/stdc++.h>
using namespace std;

vector<string> stArr;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	string st;
	cin >> st;
	stArr.push_back(st);
	int len_st = st.length();
	for (int i = 0; i <len_st-1; i++) {
		st.erase(0,1);
		stArr.push_back(st);
	}
	sort(stArr.begin(), stArr.end());
	for (auto i : stArr)
		cout << i << '\n';
}