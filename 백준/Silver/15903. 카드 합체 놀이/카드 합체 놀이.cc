#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>a[i];
    while(m--){
        swap(a[0],*min_element(a,a+n));
        swap(a[1],*min_element(a+1,a+n));
        long long tmp= a[0]+a[1];
        a[0]=tmp;
        a[1]=tmp;
    }
    long long ans=0;
    for(int i=0; i<n; i++) ans+=a[i];
    cout<< ans;
}