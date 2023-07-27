#include <bits/stdc++.h>
using namespace std;

int n , m;
vector<pair<int,int>> adj[1'005];
int d[1'005];
const int INF = 0x3f3f3f3f;

void solve(int a, int b){
    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;

    fill(d,d+1+n,INF);
    int st=a;
    d[st]=0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur=pq.top(); pq.pop();
        if(d[cur.second]!=cur.first) continue;
        for(auto nxt: adj[cur.second]){
            if(d[nxt.second]<=d[cur.second]+nxt.first)   continue;
            d[nxt.second]=d[cur.second]+nxt.first;
            pq.push({d[nxt.second],nxt.second});
        }
    }
    cout<<d[b];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }
    int a, b;
    cin>>a>>b;
    solve(a,b);

}