#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[305][305];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int chk[305][305];
int tmp[305][305];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  //체크하고, 맨 마지막에 싹 돌면서 주위 상황에 따라 숫자를 줄이는 식으로 만들자. 
  
  //초기 입력부분.
  cin>>n>>m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>board[i][j];
    }
  }
  int ans=0;
  while(true){
    // 다 녹았는데 아직도 cnt>=2 가 안되서 반복을 돌고 있는 상황이면 종료
    int pos=false;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(board[i][j]!=0) pos=true;
      }
    }
    if(!pos){
      cout<<0;
      return 0;
    }

    //1년 지나서 빙산이 녹게하기
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(board[i][j]==0) continue;
        int numzero=0;
        for(int dir=0; dir<4; dir++){
          int nx=i+dx[dir];
          int ny=j+dy[dir];
          if(board[nx][ny]==0) numzero++; 
        }
        tmp[i][j]=numzero;
      }
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        board[i][j]-=tmp[i][j];
        if(board[i][j]<0) board[i][j]=0;
      }
    }
    //1년 증가
    ans++;

    int cnt=0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        chk[i][j]=0;
      }
    }
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(board[i][j]==0) continue;
        if(chk[i][j]!=0) continue;
        chk[i][j]=1;
        q.push({i,j});
        cnt++;
        while(!q.empty()){
          auto cur=q.front(); q.pop();
          for(int dir=0; dir<4; dir++){
            int nx=cur.first+dx[dir];
            int ny=cur.second+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[nx][ny]==0) continue;
            if(chk[nx][ny]!=0) continue;
            chk[nx][ny]=1;
            q.push({nx,ny});
          }
        }
      }
    }
    if(cnt>=2) break;
  }
  cout<<ans;
}