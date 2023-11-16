#include <bits/stdc++.h>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b){
    return a[1]<b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(),routes.end(),cmp);
    int c= -30'005;
    for(auto& t: routes){
        if(t[0]>c){
            c=t[1];
            answer++;
        }
    }
    return answer;
}