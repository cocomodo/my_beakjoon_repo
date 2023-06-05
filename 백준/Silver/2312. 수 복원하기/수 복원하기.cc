#include <bits/stdc++.h>
using namespace std;

vector<bool> state(100'001,true);
vector<int> sieve(int n){
    vector<int> primes;
    state[1]=false;
    for(int i=2; i*i<=n;i++){
        if(!state[i]) continue;
        for(int j=i*i;j<=n; j+=i)
          state[j]=false;
    }
    for(int i=2;i<=n;i++)
      if(state[i]) primes.push_back(i);
    
    return primes;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    vector<int> primes=sieve(100'001);
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> divider;
        for(auto p : primes){
            int cnt=0;
            while(n%p==0){
                cnt++;
                n/=p;
            }
            if(cnt!=0)divider.push_back({p,cnt});            
            if(n==1) break;
        }
        for(auto q : divider){
            cout<<q.first<<' '<<q.second<<'\n';
        }
    }
}