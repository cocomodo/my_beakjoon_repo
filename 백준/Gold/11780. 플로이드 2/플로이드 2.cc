#include <bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;
int d[105][105];
int nxt[105][105];
int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++)
        fill(d[i],d[i]+1+n,INF);
    while(m--){
        int a, b, c;
        cin>>a>>b>>c;
        d[a][b]=min(d[a][b],c);
        nxt[a][b]=b;
    }
    for(int i=1; i<=n; i++) d[i][i] = 0;

    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                // d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    nxt[i][j]=nxt[i][k];
                } 
            
    //초기에 5*5 형태로 출력하는 값
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(d[i][j]==INF) cout<<'0'<<' ';
            else cout<<d[i][j]<<' ';
        }
        cout<<'\n';
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(d[i][j]==0 || d[i][j]==INF){
                cout<<"0\n";
                continue;
            }
            vector<int> path;
            int st=i;
            while(st!=j){ //핵심 로직
                path.push_back(st);
                st=nxt[st][j];
            }
            path.push_back(j);//이 부분이 마지막에 도착할 부분.
            cout<<path.size()<<' ';
            for(auto x: path) cout<<x<<' ';
            cout<<'\n';
        }
    }
}