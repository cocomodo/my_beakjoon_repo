#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> n, string d) {
    deque<int> dq;
    for(auto c: n){
        dq.push_back(c);
    }
    if(d=="right"){
        dq.push_front(dq.back()); dq.pop_back();
    }
    else{
        dq.push_back(dq.front()); dq.pop_front();
    }
    vector<int> answer;
    for(auto c: dq)
        answer.push_back(c);
    return answer;
}