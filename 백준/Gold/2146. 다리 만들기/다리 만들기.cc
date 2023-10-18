#include <bits/stdc++.h>
using namespace std;

int board[105][105];
int vis[105][105];
int dist[105][105];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n , cnt=0;

queue<pair<int,int>> q;

//주어진 섬들에 개별적으로 다른 번호를 붙여서 구분짓게 해주는 bfs 함수
void numbering_land(){
//cnt는 섬의 번호를 의미, board[i][j]의 값이 같은 경우 같은 섬
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(board[i][j]==0) continue;
      if(vis[i][j]==1) continue;
      cnt++;
      vis[i][j]=1;
      board[i][j]=cnt;
      q.push({i,j});
      while(!q.empty()){
        auto cur=q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
          int nx=cur.first+dx[dir];
          int ny=cur.second+dy[dir];
          if(nx<0||nx>=n||ny<0||ny>=n) continue;
          if(vis[nx][ny]==1) continue;
          if(board[nx][ny]==0) continue;
          board[nx][ny]=cnt;
          vis[nx][ny]=1;
          q.push({nx,ny});
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) 
      cin>>board[i][j];
  }
  //bfs를 돌면서 섬들에 1부터 시작하는 번호로 섬들의 땅의 값들을 바꾸어서 구분지어주는 함수.
  numbering_land();

  for(int i=0; i<n; i++)
    fill(dist[i],dist[i]+n,-1);
  
  int ans=0x7f7f7f7f;
  // 모든 육지 (i,j)의 각각에 대해 bfs를 진행. 이때 board[i][j]와 board[nx][ny]가 다른 최초의 (nx,ny)를 찾으면 (i,j)에서 시작하는 다리의 길이를 계산 가능. 

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(board[i][j]==0) continue;
      q.push({i,j});
      dist[i][j]=0;
      bool escape=false;
      while(!q.empty() && !escape){
        auto cur=q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
          int nx=cur.first + dx[dir];
          int ny=cur.second + dy[dir];
          if(nx<0||nx>=n||ny<0||ny>=n) continue;
          if(dist[nx][ny]>=0) continue;
          if(board[i][j]==board[nx][ny]) continue;
          if(board[nx][ny]!=0 && board[i][j]!=board[nx][ny]){
            ans=min(ans,dist[cur.first][cur.second]);
            while(!q.empty()) q.pop();
            escape=true;
            break;
          }
          dist[nx][ny]=dist[cur.first][cur.second]+1;
          q.push({nx,ny});
        }
      }
      for(int i=0; i<n; i++)
        fill(dist[i],dist[i]+n,-1);
    }
  }
  cout<<ans;
}