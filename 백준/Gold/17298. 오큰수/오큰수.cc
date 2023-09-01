#include <bits/stdc++.h>
using namespace std;

const int mx=1'000'000;

int a[mx];
int ans[mx];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0; i<n; i++) 
        cin>>a[i];
    stack<int> S;
    for(int i=n-1; i>=0; i--){
        while(!S.empty() && S.top()<=a[i]) 
            S.pop();
        if(S.empty())
            ans[i]=-1;
        else
            ans[i]=S.top();
        S.push(a[i]);
    }
    for(int i=0; i<n; i++) 
        cout<<ans[i]<<' ';
}