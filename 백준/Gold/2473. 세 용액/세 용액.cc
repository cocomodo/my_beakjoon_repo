#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a[5005];
int ans1,ans2,ans3;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    ll ans=3e9+1;
    for(int st=0; st<n-2;st++){
        int mid=st+1;
        int en=n-1;
        while(mid<en){
            ll cur=a[st]+a[mid]+a[en];
            if(abs(ans)>abs(cur)){
                ans=cur;
                ans1=a[st];
                ans2=a[mid];
                ans3=a[en];
            }
            if(cur>=0) en--;
            else mid++; 
        }
    }
    cout<<ans1<<' '<<ans2<<' '<<ans3;
}