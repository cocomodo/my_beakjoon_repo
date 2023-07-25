#include <bits/stdc++.h>
using namespace std;

int n, m, st, en;
vector<pair<int,int>> adj[1'005];
int d[1'005];
const int INF=0x3f3f3f3f;
int pre[1'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }
    cin>>st>>en;

    fill(d,d+n+1,INF);

    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;

    d[st]=0;
    pq.push({d[st],st});

    while(!pq.empty()){
        auto cur=pq.top(); pq.pop();
        if(d[cur.second]!=cur.first) continue;
        for(auto nxt: adj[cur.second]){
            if(d[cur.second]+nxt.first>=d[nxt.second]) continue;
            d[nxt.second]=d[cur.second]+nxt.first;
            pq.push({d[nxt.second],nxt.second});
            pre[nxt.second]=cur.second;
        }
    }
    cout<<d[en]<<'\n';
    vector<int> path;
    int cur=en;
    while(cur!=st){
        path.push_back(cur);
        cur=pre[cur];
    }
    path.push_back(cur);//st 가 된 cur 값을 담아주기. 위에서 안담기기 때문에. 
    reverse(path.begin(),path.end());
    cout<<path.size()<<'\n';
    for(auto x: path) cout<<x<<' ';
}