
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num;
    priority_queue<int, vector<int> , greater<>> pq;

    cin>>n;
    for(int i=0; i<n*n; i++){
        cin>>num;
        pq.push(num);
        if(n<pq.size()) pq.pop();//원래 n<(int)pq.size() 형태로 작성하는것이 정석이지만 이렇게 제출해봄
    }
    cout<<pq.top();
}