#include <bits/stdc++.h>
using namespace std;

int n;
stack<int> s;
int cnt=1;
string ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        while(cnt<=t){
            s.push(cnt);
            cnt+=1;
            ans+="+\n";
        }
        if(s.top()!=t){
            cout<<"NO\n";
            return 0;
        }
        s.pop();
        ans+="-\n";
    }
    cout<<ans;
}