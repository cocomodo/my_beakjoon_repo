#include <bits/stdc++.h>
using namespace std;

int n;
stack<pair<int,int>> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    s.push({100'000'005,0});
    for(int i=1; i<=n; i++){
        int h;
        cin>>h;
        while(s.top().first<=h)
            s.pop();
        cout<<s.top().second<<' ';
        s.push({h,i});
    }
}