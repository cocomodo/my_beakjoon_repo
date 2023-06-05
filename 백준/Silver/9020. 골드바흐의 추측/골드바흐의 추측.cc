#include <bits/stdc++.h>
using namespace std;

bool isprime(int n) {
	if (n == 1) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) 
			return 0;
	}
	
	return 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;

	while (n--) {
		int a;
		cin >> a;
		for (int i = a / 2; i > 1; i--) {
			if (isprime(i) && isprime(a - i)) {
				cout << i << " " << a - i<<"\n";
				break;
			}
		}
	}
}