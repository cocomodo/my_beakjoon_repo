#include <bits/stdc++.h>
using namespace std;

int board[105][105];
int vis[105][105];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    string str;
    for(int i=0; i<n; i++){
        cin>>str;
        for(int j=0; j<m;j++){
            board[i][j]=str[j]-'0';
        }
    }
    queue<pair<int,int>> Q;
    vis[0][0]=1;
    Q.push({0,0});
    while(!Q.empty()){
        auto cur=Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx=cur.first+dx[dir];
            int ny=cur.second+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(vis[nx][ny]!=0) continue;
            if(board[nx][ny]!=1) continue;
            vis[nx][ny]=vis[cur.first][cur.second]+1;
            Q.push({nx,ny});
        }
    }
    cout<<vis[n-1][m-1];
}

