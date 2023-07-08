#include <bits/stdc++.h>
using namespace std;

int n, m;
int id[1005];
vector<int> adj[1005];
vector<int> result;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    int no,u,v;
    while(m--){
        cin>>no;
        if(no==0) continue;
        cin>>u;
        while(--no){
            cin>>v;
            adj[u].push_back(v);
            id[v]++;
            u=v;//swap(u,v); 를 쓰는게 깔끔해 보이긴 하는데, 코드 동작상 이렇게 해도 된다.
        }
    }
    queue<int> q;
    for(int i=1; i<=n; i++)
        if(id[i]==0) q.push(i);
    
    while(!q.empty()){
        int cur=q.front(); q.pop();
        result.push_back(cur);
        for(int nxt: adj[cur])
            if(--id[nxt]==0) q.push(nxt);
    }
    if(result.size()!=n) cout<<0;
    else for(auto s: result) cout<<s<<'\n';
}