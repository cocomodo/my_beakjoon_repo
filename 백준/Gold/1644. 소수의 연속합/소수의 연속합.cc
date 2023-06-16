#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> sieve(int n){
    vector<int> primes;
    vector<bool> check(4000001,true);
    check[1]=false;
    for(int i=2;i*i<=4000000;i++){
        if(!check[i]) continue;
        for(int j=2*i;j<=4000000;j+=i)
            check[j]=false;//여길 자꾸 i로 작성하는데, j이다. 주의하도록 하자.
    }
    for(int i=2;i<=4000000;i++)
        if(check[i]) primes.push_back(i);
    return primes;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    vector<int> primes=sieve(n);
    primes.push_back(0);
    int ans=0, st=0,en=1,tot=primes[0];
    while(1){
        if(tot==n) ans++;
        if(tot<=n) tot+=primes[en++];
        if(tot>n) tot-=primes[st++];
        if(en==int(primes.size())) break;
    }
    cout<<ans;
}