/*
(1)(2 3 4 5 6 7) (8 9 10 11 12 13 14 15 16 17 18 19) (20, 21, ... ,37 ) (38~61)
코어     1각 =6개              2각   =12개               3각 ...=18개.      4각=24개.

결국 그 수가 주어졌을때 그것이 몇각에 위치해있는지 알아내고, 거기에 +1(코어의 시작점 포함)을 해주면
답이 나온다.

1 7 19 37 61 ... 의 끝항을 알아내는 일반항은 1+6(n-1)n/2 이다. 
예를들어 4라는 숫자를 보면, 이건 1코어 보다 높고, (k=1일때, 1)
1각의 끝(7)보다 작다 (k=2일때, 7) 그래서 k값은 1<4<2 이므로, 정답은 2 
*/

#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    k++;//k==1;로 만드는 부분.
    while((1+6*(k-1)*k/2)<n){
        k++;
    }
    cout<<k;
    
}

