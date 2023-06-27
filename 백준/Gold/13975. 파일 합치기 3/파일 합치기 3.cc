#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int t;
    cin>>t;
    while(t--){
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        int n;
        cin>>n;
        int p;
        for(int i=0; i<n; i++){
            cin>>p;
            pq.push(p);
        }
        ll ans=0;
        while((int)pq.size()>1){
            ll a=pq.top(); pq.pop();
            ll b=pq.top(); pq.pop();
            ans+=a+b;
            pq.push(a+b);
        }
        // ans+=pq.top();
        cout<<ans<<'\n';
    }
}