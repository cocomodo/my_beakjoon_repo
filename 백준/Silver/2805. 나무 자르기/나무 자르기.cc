#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int a[1'000'005];
int ans;

int solve(int x){
    long long cur=0;
    for(int i=0; i<n; i++){
        if(a[i]>x) cur+=a[i]-x;
    }
    return cur>=m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>a[i];
    int st=0;
    int en=*max_element(a,a+n);
    while(st<=en){
        int mid=(st+en)/2;
        if(solve(mid)){
            st=mid+1;
            ans=max(ans,mid);
        }
        else
            en=mid-1;
    }
    cout<<ans;
}