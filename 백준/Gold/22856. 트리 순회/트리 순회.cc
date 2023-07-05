#include <bits/stdc++.h>
using namespace std;

const int root=1;
int n, c, l, r;
int lc[100'005];
int rc[100'005];
int p[100'005];
int vis[100'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    // p[root]=-1; /* 이 코드 중요. 분석해볼곳*/
    for(int i=1; i<=n; i++){
        cin>>c>>l>>r;
        lc[c]=l;
        rc[c]=r;
        p[l]=c;
        p[r]=c;
    }
    
    int endpoint=root;
    while(rc[endpoint]!=-1){
        endpoint=rc[endpoint];
    }
    
    int cur=root;
    int move=0;
    while(true){
        vis[cur]=true; /* 이 코드 중요. 분석해볼곳*/
        move++;
        // cout<<cur<<' ';
        if(lc[cur]!=-1 && !vis[lc[cur]]) cur=lc[cur];
        else if(rc[cur]!=-1 && !vis[rc[cur]]) cur=rc[cur];
        else {
            if(cur==endpoint) break;
            else cur=p[cur];
        }
    }
    cout<<move-1;

}