#include <bits/stdc++.h>
using namespace std;

int a[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int ans=0;

    for(int i=0; i<n;i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(m>=a[i]+a[j]+a[k]&&(ans<a[i]+a[j]+a[k]))
                    ans=a[i]+a[j]+a[k];
            }
        }
    }
    cout<<ans;
}