#include <bits/stdc++.h>
using namespace std;

int board[105][105];
bool vis[105][105];
int dist[105][105];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n;
bool OOB(int a, int b){
  return a<0 || a>=n || b<0 || b>=n;
}

void island(){
  int idx=1;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(vis[i][j]) continue;
      if(board[i][j]==0) continue;
      queue<pair<int,int>> Q;
      Q.push({i,j});
      vis[i][j]=true;
      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        board[cur.first][cur.second]= idx; 
        for(int dir=0; dir<4; dir++){
          int nx=cur.first+dx[dir];
          int ny=cur.second+dy[dir];
          if(OOB(nx,ny)) continue;
          if(vis[nx][ny]) continue;
          if(board[nx][ny]==0) continue;
          Q.push({nx,ny});
          vis[nx][ny]=true;
        }
      } 
      idx++;
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin>>board[i][j];
  island();
  for(int i=0; i<n; i++)
    fill(dist[i],dist[i]+n,-1);
  queue<pair<int,int>> Q;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(board[i][j]!=0){//모든 점을 bfs의 대상으로 만들기 위해 dist 0으로 표시하고 queue에 넣기. 
        dist[i][j]=0;
        Q.push({i,j});
      }
    }
  }
  int ans=0x7f7f7f7f;
  while(!Q.empty()){
    auto cur= Q.front(); Q.pop();
    for(int dir=0; dir<4; dir++){
      int nx=cur.first+dx[dir];
      int ny=cur.second+dy[dir];
      if(OOB(nx,ny)) continue;
      if(board[nx][ny]==board[cur.first][cur.second]) continue; //인접한 섬이 같은 섬의 일부일 경우 건너뛰기
      if(board[nx][ny]!=0){
        //인접한 섬이 현재 섬과 같지 않은데 0이 아니므로 다른 섬
        ans=min(ans, dist[nx][ny]+dist[cur.first][cur.second]);
      }
      else{//바다일 경우
        board[nx][ny]=board[cur.first][cur.second];
        dist[nx][ny]=dist[cur.first][cur.second]+1;
        Q.push({nx,ny});
      }
    }
  }
  cout<<ans;
}