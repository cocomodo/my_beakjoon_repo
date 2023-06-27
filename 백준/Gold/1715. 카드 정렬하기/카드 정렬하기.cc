#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minPq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    int n;
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        minPq.push(t);
    }
    long long ans=0;
    while(minPq.size()>1){
        long long tmp=0;
        tmp+=minPq.top(), minPq.pop();
        tmp+=minPq.top(), minPq.pop();
        ans+=tmp;
        minPq.push(tmp);
    }
    cout<<ans;
}