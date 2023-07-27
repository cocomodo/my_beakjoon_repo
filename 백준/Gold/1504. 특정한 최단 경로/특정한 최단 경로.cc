#include <bits/stdc++.h>
using namespace std;

int n , m ; 
vector<pair<int,int>> adj[805];
int d[805];
const int INF= 0x3f3f3f3f;

int solve(int a, int b){
    fill(d,d+n+1,INF); 
    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;
    int st=a;
    d[st]=0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur= pq.top(); pq.pop();
        if(d[cur.second]!=cur.first) continue;
        for(auto nxt: adj[cur.second]){
            if(d[nxt.second]<=d[cur.second]+nxt.first) continue;
            d[nxt.second]=d[cur.second]+nxt.first;
            pq.push({d[nxt.second],nxt.second});
        }
    }

    return d[b];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({w, v});
        adj[v].push_back({w,u});
    }

    int v1, v2;
    cin>>v1>>v2;
    
    if(solve(1,v1)==INF || solve(1,v2)==INF || solve(v1,v2)==INF || solve(v1,n)==INF || solve(v2,n)==INF) {
        cout<<"-1";
        return 0;
    }
    int ans=0x3f3f3f3f;
    ans=min(ans,solve(1,v1)+2*solve(v1,v2)+solve(v1,n));
    ans=min(ans,solve(1,v2)+2*solve(v1,v2)+solve(v2,n));
    ans= min(ans,solve(1,v1)+solve(v1,v2)+solve(v2,n));
    ans=min(ans,solve(1,v2)+solve(v2,v1)+solve(v1,n));
    
    cout<<ans;
}

/*
네가지 경우가 잇을것이다 
아니네 6가지네 
아니네 4가지가맞네. 

st v1 v2 v1 en
st v2 v1 v2 en
st v1 v2 en
st v2 v1 en

만약 이 과정중에 하나라도 INF 가 나온다면, -1을 출력해주면 될것이다. 

*/