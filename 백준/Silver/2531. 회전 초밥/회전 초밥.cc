#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
int a[30'001*2];
int chk[3'001];
int ans;
int mxans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>d>>k>>c;
    chk[c]++;
    ans=1;
    mxans=1;
    
    for(int i=0; i<n; i++){
        cin>>a[i];
        a[n+i]=a[i];
    }

    for(int i=0; i<n*2;i++){ /* i 하나 가지고 i-k와 i 라는 인덱스를 모두 움직여서
    앞쪽에 i-k 로 시작 위치를 조정하고, i로 끝 위치를 조정하면서 상황을 컨트롤 할 수 있다*/
        if(i==n+k-1) break;/*내가 생각한 효율화 방안. 이 경우 n이 작아서 그냥 끝까지 계산해도 되겠지만, n이 커지면 이렇게 중간에 멈추어주면 훨씬 효율적이게 될것이다.*/
        if(i>=k){
            chk[a[i-k]]--;
            if(chk[a[i-k]]==0) ans--;
        }
        if(chk[a[i]]==0){
            ans++;
            mxans=max(mxans,ans);
        }
        chk[a[i]]++;
    }
    cout<<mxans;
}