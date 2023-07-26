#include <bits/stdc++.h>
using namespace std;

int n , m ,x;
vector<pair<int,int>> adj[1'005];
int d[1'005];
const int INF= 0x3f3f3f3f;

int dijkstra(int a, int b){
    fill(d,d+1+n,INF);
    
    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;

    d[a]=0;
    pq.push({d[a],a});
    while(!pq.empty()){
        auto cur= pq.top(); pq.pop();
        if(d[cur.second]!=cur.first) continue;
        for( auto nxt: adj[cur.second]){
            if(d[nxt.second]<= d[cur.second]+nxt.first)  continue;
            d[nxt.second]= d[cur.second]+nxt.first;
            pq.push({d[nxt.second],nxt.second});
        }
    }
    return d[b];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>x;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }

    int ans=0;
    for(int st=1; st<=n; st++)
        ans=max(ans, dijkstra(st,x)+dijkstra(x,st));
    cout<<ans;
}