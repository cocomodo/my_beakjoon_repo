// 5 3 2
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 1 0 0
// 0 0 0 0 0

//여러분은 토마토가 모두 익을 때까지 최소 며칠이 걸리는지를 계산해서 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.

#include <bits/stdc++.h>
using namespace std;

int board[105][105][105];
int vis[105][105][105];
int m, n, h;

int dx[6]={0,1,0,-1,0,0};
int dy[6]={1,0,-1,0,0,0};
int dz[6]={0,0,0,0,1,-1};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin>> m >> n >> h;
  // h먼저 받고, 나머지 m, n 순서로 받도록 하자. 
  for(int k=0; k<h; k++){
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin>>board[k][i][j];
      }
    }
  }
  bool impossilbe=false; 
  for(int k=0; k<h; k++){
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(board[k][i][j]==0){
          impossilbe=true; 
        }
      }
    }
  }
  if(impossilbe==false){
    cout<<0;
    return 0;
  }
  queue<tuple<int,int,int>> Q;
  for(int k=0; k<h; k++){
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(board[k][i][j]==1){
          vis[k][i][j]=1;
          Q.push({k,i,j});
        }
      }
    }
  }
  while(!Q.empty()){
    auto cur=Q.front(); Q.pop();
    for(int dir=0; dir<6; dir++){
      int nx=get<1>(cur)+dx[dir];
      int ny=get<2>(cur)+dy[dir];
      int nz=get<0>(cur)+dz[dir];
      if(nx<0 || nx>=n || ny<0 || ny>=m || nz<0 || nz>=h) continue;
      if(board[nz][nx][ny]==-1) continue;//비어있다면
      if(vis[nz][nx][ny]!=0) continue;//이미 방문했다면
      vis[nz][nx][ny]=vis[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
      Q.push({nz,nx,ny});
      // cout<<"h";
    }
  }
  for(int k=0; k<h; k++){
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(board[k][i][j]==-1) vis[k][i][j]=-1;
      }
    }
  }
  int mx=0;
  for(int k=0; k<h; k++){
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(vis[k][i][j]==0) {
          cout<<"-1";
          return 0;
        }
        mx=max(mx,vis[k][i][j]);
      }
    }
  }
  cout<<mx-1;

  // cout<<'\n';
  // for(int k=0; k<h; k++){
  //   for(int i=0; i<n; i++){
  //     for(int j=0; j<m; j++){
  //       cout<<vis[k][i][j]<<' ';
  //     }
  //     cout<<'\n';
  //   }
  //   cout<<'\n';
  // }

}

