//주의할점, 입력이 m 과 n이 반대로 주어진다
//다 돌리고 최대값이 1이면 출력 0을 한다
//다 돌리고도 0인 부분이 존재한다면 -1을 출력한다. 안익으니까
//board가 -1이 아닌데 0인 부분(거리가) 라고 해야겠지

#include <bits/stdc++.h>
using namespace std;

int board[1005][1005];
int dist[1005][1005];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> q;
    cin>>m>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dist[i][j]=-1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
            if(board[i][j]==1){
                q.push({i,j});
                dist[i][j]=0;
            }
        }
    }
    bool finish=true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]==0){
                finish=false;
            }  
        }
    }
    if(finish==true){
        cout<<0;
        return 0;
    }
    
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx=cur.first+dx[dir];
            int ny=cur.second+dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(dist[nx][ny]!=-1) continue;
            if(board[nx][ny]==-1) continue;
            dist[nx][ny]=dist[cur.first][cur.second]+1;
            q.push({nx,ny});
        }
    }
    int mx=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]!=-1 && dist[i][j]==-1){
                cout<<"-1";
                return 0;
            }
            mx=max(mx,dist[i][j]);
        }
    }
    cout<<mx;
}