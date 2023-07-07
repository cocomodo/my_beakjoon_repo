#include <bits/stdc++.h>
using namespace std;

int n;
int lc[10'005];
int rc[10'005];
int colno,root;
pair<int,int> colLR[10'005];//열 번호가 가장 작은 값과 큰 값을 저장할 페어 배열

void inorder(int cur, int d){
    if(cur==-1) return; /*애초에 배열로 받을 때 -1까지 받아서, 이런식으로
    코드를 작성한다 */
    inorder(lc[cur],d+1);//depth를 증가시켜서 다음 순회로 넘어간다.
    colno++; /*중위에서 colno를 증가시키면 중위순회에서 방문 순서와 같게 colno가 
    증가하게 된다.*/
    auto &[lcol,rcol] =colLR[d];
    if(!lcol || colno<lcol) lcol=colno;/* 각 깊이 d 에 대해서, lcol 값이 0이거나, colno가 lcol 값보다 더 작으면 lcol 값을 colno 값으로 갱신 */
    if(!rcol || colno>rcol) rcol=colno;/* 각 깊이 d 에 대해서, rcol 값이 0이거나, colno가 rcol 값보다 더 크면 rcol 값을 clono 값으로 갱신 */
    inorder(rc[cur],d+1);

    /* 노드가 루트 하나인 경우나, 루트 하나와 자식 하나 있는 경우는, 
    각각의 깊이 d당 노드가 딱 하나라 lcol 값과 rcol 값이 같게 된다.
    각 깊이당 노드가 2개 이상 있어야 lcol 혹은 rcol 값이 갱신 되어서
    lcol!=rcol 이 된다. */

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    vector<bool> isRoot(n+1,true);
    for(int i=0; i<n; i++){
        int p, l, r;
        cin>>p>>l>>r;
        lc[p]=l;
        rc[p]=r;

        if(l!=-1) isRoot[l]=false;
        if(r!=-1) isRoot[r]=false;
    }
    for(int i=1; i<=n; i++){
        if(isRoot[i]){
            root=i;
            break;
        }
    }
    int mxWidth=0, mxDepth=0;
    inorder(root,0);
    for(int d=0; d<n; d++){
        auto [lcol,rcol] = colLR[d];
        // if(lcol+rcol==0) break; 이 경우는 lcol==0, rcol==0 인 경우일텐데 이런 경우 없을 것이라는 
        //생각에 테스트용 제출
        int width=rcol-lcol+1;
        if(mxWidth<width){
            mxWidth = width;
            mxDepth=d;
        }
    }
    cout<<mxDepth+1<<' '<<mxWidth;

}