#include <bits/stdc++.h>
using namespace std;

int a[1'000'005];

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long ans=0;
        for(int i=0; i<n; i++)
            cin>>a[i];
        int max_val=a[n-1];
        for(int i=n-2;i>=0;i--){
            if(a[i]>max_val) max_val=a[i];
            ans+=max_val-a[i];
        }
        cout<<ans<<'\n';
    }
}