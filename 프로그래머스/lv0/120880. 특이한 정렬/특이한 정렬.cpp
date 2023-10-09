#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first) return a.second>b.second;
    else return a.first<b.first;
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    vector<pair<int,int>> a;
    int len=numlist.size();
    for(int i=0; i<len; i++){
        a.push_back({abs(n-numlist[i]),numlist[i]});
    }
    sort(a.begin(),a.end(),comp);
    for(auto c: a){
        answer.emplace_back(c.second);
    }
    return answer;
}