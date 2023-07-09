#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1'005];
int deg[1'005];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int pd,u,v;
        cin>>pd;
        cin>>u;
        while(--pd){
            cin>>v;
            adj[u].push_back(v);
            deg[v]++;
            u=v;//swap(u,v); 도 가능.
        }
    }    
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(deg[i]==0) q.push(i);
    }
    vector<int> result;
    while(!q.empty()){
        int cur=q.front(); q.pop();
        result.push_back(cur);
        for(int nxt: adj[cur]){
            if(--deg[nxt]==0) q.push(nxt);
        }
    }
    if(result.size()!=n) cout<<0;
    else for(auto x : result) cout<<x<<'\n';

}