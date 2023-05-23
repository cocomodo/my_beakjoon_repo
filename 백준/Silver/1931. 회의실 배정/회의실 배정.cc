#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    int cnt=1;
    int now=v[0].first;
    for(int i=1; i<n; i++){
        if(now<=v[i].second) {
            now=v[i].first;
            cnt++;
        }
    }
    cout<<cnt;
}