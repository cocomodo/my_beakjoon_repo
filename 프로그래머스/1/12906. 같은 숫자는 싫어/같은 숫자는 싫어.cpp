#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int t=-1;
    for(auto c: arr){
        if(t!=c){
            t=c;
            answer.push_back(c);
        }
    }
    return answer;
}