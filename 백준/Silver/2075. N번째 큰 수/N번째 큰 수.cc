#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int,vector<int>, greater<int>> pq;
    int n;
    cin>>n;
    int t;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>> t;
            pq.push(t);
            if(n<(int)pq.size())  pq.pop();
        }
    }
    cout<<pq.top();
}