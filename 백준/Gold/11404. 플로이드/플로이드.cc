/*
무한대로 초기화
0으로 대각선 초기화
주어진 길이 입력
3중포문 다이나믹 프로그래밍
무한대인 값은 0으로 출력하도록 초기화
출력
*/

#include <bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f; //=> 이 값은 10억이 조금 넘는 값이다. 
int d[105][105];
int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for(int i=1; i<=n; i++){
        fill(d[i],d[i]+1+n,INF);
    }
    for(int i=1; i<=n; i++){
        d[i][i]=0;
    }

    for(int i=1; i<=m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        d[a][b]=min(d[a][b],c);
    }

    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(d[i][j]==INF) cout<<"0 ";
            else cout<<d[i][j]<<' ';
        }
        cout<<'\n';
    }

}