#include <bits/stdc++.h>
using namespace std;

vector<int> adj[505];
int dist[505];

int n, m; 
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(dist,dist+505,-1);
    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue<int> q;
    q.push(1);
    dist[1]=0;
    int cnt=0;
    while(!q.empty()){
        int cur=q.front(); q.pop();
        for(auto nxt: adj[cur]){
            if(dist[nxt]!=-1) continue;
            q.push(nxt);
            
            dist[nxt]=dist[cur]+1;
            if(dist[nxt]<=2) ans++;
        }
    }
    cout<<ans;
}