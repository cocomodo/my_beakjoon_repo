#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    string s, p;
    unordered_map<string,string> umap;

    cin>>n>>m;
    while(n--){
        cin>>s>>p;
        umap[s]=p;
    }
    while(m--){
        cin>>s;
        cout<<umap[s]<<'\n';
    }
}