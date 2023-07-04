#include <bits/stdc++.h>
using namespace std;

int n, c, l, r, root=1;
int lc[100'005];
int rc[100'005];
int p[100'005];
vector<bool> vis(100'005);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    // p[root]=-1;
    for(int i=0; i<n; i++){
        cin>>c>>l>>r;

        /* 여기서 -1 이어도 이런 식으로 받는게 중요하다.*/
            lc[c]=l;
            p[l]=c;
        
        
            rc[c]=r;
            p[r]=c;
       
    }

    int endpoint=root;
    while(rc[endpoint]!=-1){
        endpoint=rc[endpoint];
    }
    int cur=root;
    int cnt=0;
    while(true){
        vis[cur]=true;
        cnt++;
        if(lc[cur]!=-1 && !vis[lc[cur]])
            cur=lc[cur];
        else if(rc[cur]!=-1 && !vis[rc[cur]])
            cur=rc[cur];
        else{
            if(endpoint==cur)
                break;
            else
                cur=p[cur];
        }
    }
    cout<<cnt-1;
}