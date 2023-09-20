// 5
// RRRBB
// GGBBB
// BBBRR
// BBRRR
// RRRRR
// 출력: 4 3
//적록색약 이니까, R와 G이 구분이 안되게 해야한다. 

//일단 입력받은 자료를 쪼개도록하자

#include <bits/stdc++.h>
using namespace std;

string str;
int n;
char board[105][105];
int vis[105][105];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int bfs(char c){
  int cnt=0;
  for(int i=0; i<105;i++)
    fill(vis[i],vis[i]+105,0);
  queue<pair<int,int>> Q;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(board[i][j]!=c) continue;
      if(vis[i][j]==1) continue;
      vis[i][j]=1;
      Q.push({i,j});
      cnt++;
      while(!Q.empty()){
        auto cur=Q.front(); Q.pop();
        // cnt++;
        for(int dir=0; dir<4; dir++){
          int nx=cur.first+dx[dir];
          int ny=cur.second+dy[dir];
          if(nx<0||nx>=n||ny<0||ny>=n) continue;
          if(board[nx][ny]!=c) continue;
          if(vis[nx][ny]==1) continue;
          vis[nx][ny]=1;
          Q.push({nx,ny});  
        }
      }
    }
  }
  return cnt;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;

  for(int i =0; i<n; i++){
    cin>>str;
    for(int j=0; j<n; j++){
      board[i][j]=str[j];
    }
  }
  // for(int i=0; i<n; i++){
  //   for(int j=0; j<n; j++){
  //     cout<<board[i][j]<<' ';
  //   }
  //   cout<<'\n';
  // }
  // cout<<bfs('R')<<' '<<bfs('G')<<' '<<bfs('B');
  cout<<bfs('R')+bfs('G')+bfs('B')<<' ';
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(board[i][j]=='G') board[i][j]='R';
    }
  }
  cout<<bfs('R')+bfs('B');
}