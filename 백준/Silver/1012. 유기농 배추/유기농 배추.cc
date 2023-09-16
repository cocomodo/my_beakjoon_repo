#include <bits/stdc++.h>
using namespace std;

int m, n, k;
int tc;

int board[55][55];
int vis[55][55];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin>>tc;
  while(tc--){
    cin>>m>>n>>k;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        board[i][j]=0; // 초기화 || fill 함수 사용해도 됨
      }
    }
    for(int i=0; i<n; i++){ // vis배열 초기화
        for(int j=0; j<m; j++){
            vis[i][j]=0;
        }
    }
    while(k--){ //맵 입력
      int x,y;
      cin>>x>>y;
      board[y][x]=1;
    }
    
    queue<pair<int,int>> q;
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]==1) continue;
            if(board[i][j]==0) continue;
            vis[i][j]=1;
            q.push({i,j});
            ans++;
            while(!q.empty()){
                auto cur=q.front(); q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx=cur.first+dx[dir];
                    int ny=cur.second+dy[dir];
                    if(nx<0|| nx>=n||ny<0||ny>=m) continue;
                    if(vis[nx][ny]==1) continue;
                    if(board[nx][ny]==0) continue;
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    cout<<ans<<'\n';
  }
}