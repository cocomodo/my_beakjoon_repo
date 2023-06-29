#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
bool vis[105];


int n, m; 
int ans;

void dfs(int cur){
    vis[cur]=true;
    for(auto nxt: adj[cur]){
        if(vis[nxt]) continue;
        ans++;
        dfs(nxt);
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    cout<<ans;

}
/*
방문 순서가 중요한것이 아니라 방문을 몇개의 컴퓨터에 했는지가 중요하므로, 
dfs를 활용한 풀이로 코드 작성을 간결하게 만들 수 있다. 
*/