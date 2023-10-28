#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    return answer;
    priority_queue< int,
                    vector<int>,
                    less<int>> pq;
    for(auto t: priorities) pq.push(t);
    cout<<pq.size()<<'\n';
    for(int i=0; pq.size();i++){
        cout<<pq.top()<<'\n';
        pq.pop();
    }
}