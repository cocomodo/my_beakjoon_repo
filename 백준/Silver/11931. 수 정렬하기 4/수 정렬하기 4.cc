#include <bits/stdc++.h>
using namespace std;

int n;
int a[1'000'005];

bool compare(const int &a, const int &b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n,compare);
    for(int i=0; i<n; i++) cout<<a[i]<<'\n';
}