#include <bits/stdc++.h>
using namespace std;

int n, m;
// int a[10'005];
vector<int> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        v.push_back(t);
    }
    v.push_back(0);
    int ans=0,st=0,en=1,tot=v[0];
    //a[n]==0; 전역변수로 선언했기 때문에 초기화가 0으로 되어있어서 불필요한 코드.
    while(1){
        if(tot==m) ans++;
        if(tot<=m) tot+=v[en++];
        if(tot>m) tot-=v[st++];
        if(en==int(v.size())) break;
    }
    cout<<ans;
}