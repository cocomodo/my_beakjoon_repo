#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin>>n;
    vector<pair<int,int>> flowers;
    int sm,sd,em,ed;
    for(int i=0; i<n; i++){
        cin>>sm>>sd>>em>>ed;
        flowers.push_back({sm*100+sd,em*100+ed});
    }
    int t=301;
    int ans=0;
    while(t<1201){
        int nxt_t=t;
        for(int i=0; i<n; i++){
            if(flowers[i].first<=t&&flowers[i].second>nxt_t)
                nxt_t=flowers[i].second;
        }
        if(nxt_t==t){
            cout<<'0';
            return 0;
        }
        ans++;
        t=nxt_t;
    }
    cout<<ans;
}