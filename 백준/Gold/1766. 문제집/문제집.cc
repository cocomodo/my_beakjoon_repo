#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[32'005];
int deg[32'005];
priority_queue<int,vector<int>, greater<int>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    while(m--){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        deg[v]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++)
        if(deg[i]==0)  pq.push(i);

    while(!pq.empty()){
        int cur=pq.top(); pq.pop();
        if(deg[cur]==0) {
        // q.push(cur);
        cout<<cur<<' ';
        }
        for(int nxt: adj[cur]){
            deg[nxt]--;
            if(deg[nxt]==0) pq.push(nxt);
        }
    }

}