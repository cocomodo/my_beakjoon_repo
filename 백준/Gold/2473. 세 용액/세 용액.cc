#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a[5005];
int ans1,ans2,ans3;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    ll ans=3e9+1;
    for(int st=0; st<n-2;st++){
        int mid=st+1;
        int en=n-1;
        while(mid<en){
            ll cur=1ll*a[st]+a[mid]+a[en];/*여기서 오른쪽 계산이, int a[5005]; 로
            선언한 상태에서 ll cur= a[st]+a[mid]+a[en]; 으로 작성하면, 
            오른쪽의 연산에서 int overflow가 발생한다. 아주아주 생각을 못해내다가
            뒤늦게 찾았다. 이걸 피하기 위해서는 int a[5005] 로 선언했으면,
            ll cur = (long long)(a[st]+a[mid]+a[en]); 형태로 계산하던지, 
            아니면 1ll을 곱해주어서 캐스팅 해주어야 한다. */
            if(abs(ans)>abs(cur)){
                ans=cur;
                ans1=a[st];
                ans2=a[mid];
                ans3=a[en];
            }
            if(cur>=0) en--;
            else mid++; 
        }
    }
    cout<<ans1<<' '<<ans2<<' '<<ans3;
}