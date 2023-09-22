#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string str) {
    vector<int> answer;
    for(auto c: str){
        if(c-'0'>=0 && c-'0'<=9) answer.emplace_back(c-'0');
    }
    sort(answer.begin(),answer.end());
    return answer;
}