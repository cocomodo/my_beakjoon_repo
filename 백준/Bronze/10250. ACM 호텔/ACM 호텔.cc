#include <bits/stdc++.h>
using namespace std;
int w, h, n;
int t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> h>> w >> n;
		//n/h+1은 호실을 나타내기 위한 부분
		//근데 만약 딱 나누어 떨어지면, +1을 하면 안된다
		//예를들어 1 1 1 인 경우, 이 식은 값이 2가 나온다. 
		//101호라고 출력이 되야하는데, 2가 나온다. 
		//n%h가 0이 되는 경우들은 모두 잘못 된 출력 형태를 보인다. 
		if (n % h == 0) {
			 cout << 100 * h + (n / h ) << '\n';
			/*else cout << 100 * h + (n / h + 1) << '\n';*/
		
		}
		else {
			/*if (n / h == 0) cout << (n % h) * 100 + (n / h) << '\n';*/
			 cout << (n % h) * 100 + (n / h + 1) << '\n';
		} 
	}
}