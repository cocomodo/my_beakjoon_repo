#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[300][300];
const int INF=0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        fill(d[i],d[i]+1+n,INF);
        d[i][i]=0;
    }

    while(m--){
        int a, b, c;
        cin>>a>>b>>c;
        if(c==1){// 양방향길.
            d[a][b]=0;
            d[b][a]=0;
        }
        else{ //일방통행길. 
            d[a][b]=0;
            d[b][a]=1;
        }
    }
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++){
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }
            }    
    int tc;
    cin>>tc;
    while(tc--){
        int u,v;
        cin>>u>>v;
        cout<<d[u][v]<<'\n';
    }
}