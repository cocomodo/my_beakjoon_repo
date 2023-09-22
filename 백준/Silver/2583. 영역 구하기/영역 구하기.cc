// 5 7 3
// 0 2 4 4
// 1 1 2 5
// 4 0 6 2

// 3
// 1 7 13

// 위에 주어지는 4자리 좌표를 통해서 해당 보드에 1을 입히는 방식으로 구현하면 될것같다. 

#include <bits/stdc++.h>
using namespace std;
//이 문제에서는 m이 row를, n이 column을 의미한다. 주의
//그래서 오히려 내가 반대로 받는게 나을것 같다. 

int board[105][105];//모든 보드를 1로 채워놓고, 그 뒤에 좌표값을 받아서 해당 좌표값들의 위치를 0 으로 초기화 하는 방향으로 가자 

int vis[105][105];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int m, n, k;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>k;
  
  //모든 보드 1로 초기화. 주어지는 좌표로 0으로 부분 채울 예정
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      board[i][j]=1;
    }
  }
  while(k--){
    int x1,y1,x2,y2;
    cin>>y1>>x1>>y2>>x2;
    for(int i=x1; i<x2; i++){
      for(int j=y1; j<y2; j++){
        board[i][j]=0;
      }
    }
  }
  // for(int i=0; i<n; i++){
  //   for(int j=0; j<m; j++){
  //     cout<<board[i][j]<<' ';
  //   }
  //   cout<<'\n';
  // }
  queue<pair<int,int>> Q;
  vector<int> V;
  int cnt=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(vis[i][j]==1) continue;
      if(board[i][j]==0) continue;
      vis[i][j]=1;
      Q.push({i,j});
      cnt++;
      int area=1;
      // cout<<"h1"<<' ';
      while(!Q.empty()){
        // cout<<"h2"<<' ';
        auto cur= Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
          int nx=cur.first+dx[dir];
          int ny=cur.second+dy[dir];
          if(nx<0||nx>=n||ny<0||ny>=m) continue;
          if(vis[nx][ny]==1) continue;
          if(board[nx][ny]==0) continue;
          vis[nx][ny]=1;
          Q.push({nx,ny});
          area++;
          // cout<<"h"<<' ';
        }
      }
      V.emplace_back(area);
    }
  }
  sort(V.begin(),V.end());
  cout<<cnt<<'\n';
  for(auto c:V){
    cout<<c<<' ';
  }
}