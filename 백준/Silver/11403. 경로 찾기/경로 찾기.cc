#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
int vis[105];
int n;

void dfs(int x){
    for(int i=0; i<(int)adj[x].size(); i++){
        if(vis[adj[x][i]]) continue;
        vis[adj[x][i]]=1;
        dfs(adj[x][i]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int t;
            cin>>t;
            if(t) adj[i].push_back(j);
        }
    }

    for(int i=0; i<n; i++){
        fill(vis,vis+105,0);
        dfs(i);
        for(int j=0; j<n; j++){
            cout<<vis[j]<<' ';
        }
        cout<<'\n';
    }    
}