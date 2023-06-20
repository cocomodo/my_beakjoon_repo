#include <bits/stdc++.h>
using namespace std;

int n, m; 
string i2s[100'005];
unordered_map<string,int> s2i;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>i2s[i];
        s2i[i2s[i]]=i;
    }
    while(m--){
        string query;
        cin>>query;
        if(isdigit(query[0])){
            cout<<i2s[stoi(query)]<<'\n';
        }
        else{
            cout<<s2i[query]<<'\n';
        }
    }
}