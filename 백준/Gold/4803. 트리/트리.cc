#include <bits/stdc++.h>
using namespace std;

int n, m, tc, Trees;
vector<int> adj[505];
bool vis[505];
bool isTree;

void dfs(int cur, int prev){
    // vis[cur]=true;
    // isTree=true;
    for(auto nxt: adj[cur]){
        if(nxt==prev) continue; //부모는 제외.
        if(vis[nxt]){
            isTree=false;
            continue;
        }
        vis[nxt]=true;//이거 한줄 안했다고 메모리 초과가 난다고? 분석해보자.
        dfs(nxt,cur);
    }
} 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true){
        fill(vis,vis+n+1,0);
        cin>>n>>m;
        if(n==0 && m==0) break;
        
        for(int i=1; i<=n; i++){
            adj[i].clear();
        }
        
        while(m--){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Trees=0;
        for(int i=1; i<=n; i++){
            if(vis[i]) continue;
            vis[i]=true;
            isTree=true;
            dfs(i,-1);
            Trees+=isTree;
        }
        cout<<"Case "<<++tc<<": ";
        if(Trees==1) cout<<"There is one tree."<<'\n';
        else if(Trees>1) cout<<"A forest of "<<Trees<<" trees."<<'\n';
        else cout<<"No trees."<<'\n';
    }
}