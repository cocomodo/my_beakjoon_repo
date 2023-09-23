// 5
// 6 8 2 6 2
// 3 2 3 4 6
// 6 7 3 3 2
// 7 2 5 3 6
// 8 9 5 2 7

// 2<=n<=100 // 1<=h<=100

// 5

#include <bits/stdc++.h>
using namespace std;

int board[105][105];
int vis[105][105];
int cboard[105][105];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int n; 

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin>>n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>board[i][j];
    }
  }
  //안전영역의 극단을 생각해보면, 모두 높이가 1일때, 한개, 혹은 0개// 결국 최대 갯수는 1이 최대이다 이 경우.
  int mxh=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      mxh=max(mxh,board[i][j]);
    }
  }
  int answer=0;
  // 만약 mxh가 1이면 어떻게 되는가? 
  // for(int i=1; i<=0; i++){ 이거 출력 안된다. 
  //   cout<<"출력 되요?"<<' ';
  // }
  for(int i=0; i<=mxh;i++){//이건 횟수의 의미로 생각해야한다. 예를들어 최대 높이가 8이라면, 비가 1 왔을때, 2 왔을때, ... 8 왔을때 등을 생각할 수 있을 것이다. 그렇게 측정하기 위한 for문이다.  
    
    for(int i=0; i<n; i++){//매번 방문 보드 초기화
      for(int j=0; j<n; j++){
        vis[i][j]=0;
      }
    }
    
    int cnt=0;
    queue<pair<int,int>> Q;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(vis[i][j]==1) continue;
        if(board[i][j]<=0) continue;
        vis[i][j]=1;
        Q.push({i,j});
        cnt++;
        while(!Q.empty()){
          auto cur=Q.front(); Q.pop();
          for(int dir=0; dir<4; dir++){
            int nx= cur.first+dx[dir];
            int ny= cur.second+dy[dir];
            if(nx<0|| nx>=n || ny<0 || ny>=n) continue;
            if(vis[nx][ny]==1) continue;
            if(board[nx][ny]<=0) continue;
            vis[nx][ny]=1;
            Q.push({nx,ny});
          }
        }
      }
    }
    answer=max(answer, cnt);
    for(int i=0; i<n; i++){//매번 새로 입힐 필요가 있나?
      for(int j=0; j<n; j++){
        board[i][j]-= 1;//한번 진행될때마다 1씩 빼면 될듯
      }
    }
  }
  cout<<answer;
}