#include <bits/stdc++.h>
using namespace std;

int n;
const int MX=1'000'005;
int a[MX];
int ans[MX];
stack<int> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=n-1; i>=0; i--){
        while(!s.empty() && s.top() <= a[i])
            s.pop();
        if(s.empty())
            ans[i]=-1;
        else
            ans[i]=s.top();
        s.push(a[i]);
    }
    for(int i=0; i<n; i++)
        cout<<ans[i]<<' ';
}