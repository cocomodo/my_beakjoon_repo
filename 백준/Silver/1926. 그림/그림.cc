#include <bits/stdc++.h>
using namespace std;

int a[505][505];
bool vis[505][505];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0}; //아래 오른쪽 위 왼쪽 순


int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>a[i][j];

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++)
    //         cout<<a[i][j]<<' ';
    //     cout<<'\n';
    // }
    int cnt=0;
    int mxArea=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            queue<pair<int,int>> q;
            if(a[i][j]!=1) continue;
            if(vis[i][j]==1) continue;
            vis[i][j]=1;
            q.push({i,j});
            cnt++;
            int area=0;
            while(!q.empty()){
                auto cur=q.front(); q.pop();
                for(int nxt=0; nxt<4; nxt++){
                    int nx=cur.first+dx[nxt];
                    int ny=cur.second+dy[nxt];
                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    if(a[nx][ny]!=1) continue;
                    if(vis[nx][ny]==1) continue;
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
                area++;
            }
            mxArea=max(mxArea,area);
        }
    }
    cout<<cnt<<'\n';
    cout<<mxArea;
}