#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[8]={1,0,-1,0,1,-1,-1,1};
int dy[8]={0,1,0,-1,1,1,-1,-1};


int solution(vector<vector<int>> board) {
    int answer = 0;
    int n=board.size();
    // cout<<n<<": n의 값";
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            if(board[i][j]==1){
                for(int dir=0; dir<8; dir++){
                    int nx=i+dx[dir];
                    int ny=j+dy[dir];//여기를 i로 놓아서 잘못됨. y의 좌표로 놓아야 하니까 j로 놓아야 한다. 
                    if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                    if(board[nx][ny]==2) continue;
                    if(board[nx][ny]==1) continue;
                    if(board[nx][ny]==0) board[nx][ny]=2;
                }
            }
        }
    } 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]==0) answer++;
        }
    }
    //위험지역 체크한 보드를 확인해보기 위한 보드 출력
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
    return answer;
}