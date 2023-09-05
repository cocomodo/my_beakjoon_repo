#include <bits/stdc++.h>
using namespace std;

int n;
stack<pair<int,int>> s;
long long ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        int h;
        cin>>h;
        int idx=i;
        while(!s.empty() && s.top().first>=h){
            ans=max(ans,1LL*(i-s.top().second)*s.top().first);
            idx=s.top().second;
            s.pop();
        }
        s.push({h,idx});
    }
    while(!s.empty()){
        ans=max(ans,1LL*(n-s.top().second)*s.top().first);
        s.pop();
    }
    cout<<ans;
}