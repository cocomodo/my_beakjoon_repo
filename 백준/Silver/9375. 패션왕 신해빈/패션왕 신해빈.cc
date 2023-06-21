#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        string a, b;
        unordered_map<string,int> cloth;
        while(n--){
            cin>>a>>b;
            cloth[b]++;
        }
        int ans=1;
        for(auto c: cloth)  ans*=c.second+1;
        cout<<ans-1<<'\n';
    }
}