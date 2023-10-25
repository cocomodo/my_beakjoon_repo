#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& t1, vector<int>& t2){
    return t1[1]<t2[1];
}


int solution(vector<vector<int>> targets) {
    int answer= 0;
    int target=-1;
    sort(targets.begin(),targets.end(), cmp);
    for(auto tc: targets){
        if(tc[0]<target && tc[1]>=target) continue;
        else{
            answer++;
            target=tc[1];
        }
    }
    return answer;
}
