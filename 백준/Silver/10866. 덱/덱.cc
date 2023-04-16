#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	deque<int> dq;

	cin >> n;
	while (n--)
	{
		cin >> s;
		if (s == "push_back") {
			int t;
			cin >> t;
			dq.push_back(t);
		}
		else if (s == "push_front") {
			int t;
			cin >> t;
			dq.push_front(t);
		}
		else if (s == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else cout << -1 << '\n';
		}
		else if (s == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else cout << -1 << '\n';
		}
		else if (s == "size") cout << dq.size() << '\n';
		else if (s == "empty")
		{
			if (dq.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (s == "front")
		{
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.front() << '\n';
		}
		else//back
		{
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.back() << '\n';
		}
	}
}