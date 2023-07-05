#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<pair<int,int>> adj[1'005];
int vis[1'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0; i<n-1; i++){
        int u, v, d;
        cin>>u>>v>>d;
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }

    while(q--){
        fill(vis,vis+n+1,0);
        int u, v;
        cin>>u>>v;

        queue<pair<int,int>> q;
        q.push({u,0});
        vis[u]=true;
        while(!q.empty()){
            auto [cur,dist] =q.front(); q.pop();
            if(cur==v){
                cout<<dist<<'\n';
                break; //break면 while문을 깨고 나갈것이고, continue면 아래 내용을 건너뛰고 다음 반복단계로 들어갈것이다.
            }
            for(auto [nxt,nxtDist]:adj[cur]){
                if(vis[nxt]) continue;
                vis[nxt]=true;
                q.push({nxt,nxtDist+dist});
            }
        }

    }
}