#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100'005];
int ans=2*(1e9)+1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0; i<n; i++){
        int tmp=lower_bound(a,a+n,a[i]+m)-a;
        if(tmp==n) break; 
        ans=min(ans,a[tmp]-a[i]);
    }
    cout<<ans;
}