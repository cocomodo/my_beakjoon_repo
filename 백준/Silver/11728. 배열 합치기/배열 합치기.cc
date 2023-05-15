#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1'000'005];
int b[1'000'005];
int c[2'000'055];



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin>>n>>m;
    for(int i=0; i<n;i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];

    int idx_A=0;
    int idx_B=0;
    for(int i=0; i<n+m; i++) {
        if(idx_B==m) c[i]=a[idx_A++];
        else if(idx_A==n) c[i]=b[idx_B++];
        else if(a[idx_A]<=b[idx_B]) c[i]=a[idx_A++];
        else c[i]=b[idx_B++];
    }
    for(int i=0; i<n+m; i++) cout<< c[i]<<' ';
}