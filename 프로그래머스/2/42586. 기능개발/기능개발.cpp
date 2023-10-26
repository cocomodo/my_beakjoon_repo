#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    queue<int> qt;
    for(auto tc: progresses) q.push(tc);
    for(auto tc: speeds) qt.push(tc);
    int t=0;
    while(true){
        int p=0;
        t++;
        while(!q.empty()&&q.front()+t*qt.front()>=100){
            p++;
            q.pop();
            qt.pop();
        }
        if (p!=0) answer.push_back(p);
        if(q.empty()) break;
    }
    
    return answer;
}