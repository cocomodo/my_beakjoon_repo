#include <bits/stdc++.h>
using namespace std;

int a[2'250'000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int t;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>> a[i*n+j];
        }
    }
    sort(a,a+n*n);
    cout<<a[n*n-1-(n-1)];
}
