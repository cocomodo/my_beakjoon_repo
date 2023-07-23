#include <bits/stdc++.h>
using namespace std;

int v, e, st;

vector<pair<int,int>> adj[20'005];
const int INF = 0x3f3f3f3f;
int d[20'005]; //최단 거리 테이블

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>v>>e>>st;
    fill(d,d+1+v,INF);
    while(e--){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }
    priority_queue< pair<int,int>, 
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq; //min heap. 우선순위 큐
    
    d[st]=0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur=pq.top(); pq.pop(); //{비용, 정점 번호}
        //거리가 d에 있는 값과 다를 경우 넘어감
        if(d[cur.second]!=cur.first) continue;
        for(auto nxt: adj[cur.second]){
            if(d[nxt.second]<= d[cur.second]+nxt.first)
                continue;
            //cur 을 거쳐가는 것이 더 작은 값을 가질 경우
            //d[nxt.second]를 갱신하고 우선순위 큐에 (거리, nxt.second) 를 추가
            d[nxt.second] = d[cur.second] + nxt.first;
            pq.push({d[nxt.second],nxt.second});
        }
    }
    for(int i=1; i<=v; i++){
        if(d[i]==INF) cout<<"INF"<<'\n';
        else cout<<d[i] <<'\n';
    }
}