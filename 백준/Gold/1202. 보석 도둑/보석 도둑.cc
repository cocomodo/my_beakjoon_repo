#include <bits/stdc++.h>
using namespace std;

pair<int,int> jewel[300'005];
multiset<int> bags;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>jewel[i].second>>jewel[i].first;
    }
    sort(jewel,jewel+n);

    for(int i=0;i<k; i++){
        int c;
        cin>>c;
        bags.insert(c);
    }
    long long ans=0;
    for(int i=n-1;i>=0;i--){
        int m, v;
        tie(v, m)=jewel[i];
        auto it=bags.lower_bound(m);
        if(it==bags.end()) continue;
        ans+=v;
        bags.erase(it);
    }
    cout<<ans;
}