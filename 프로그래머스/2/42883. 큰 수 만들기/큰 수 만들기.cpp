#include <bits/stdc++.h>

using namespace std;

string solution(string numbers, int k){
    string answer="";
    stack<char> s;
    
    for(char num: numbers){
        while(!s.empty() && s.top() < num && k>0){
            s.pop();
            k--;
        }
        s.push(num);
    }
    while(k>0){
        s.pop();
        k--;
    }
    while(!s.empty()){
        answer=s.top()+answer;
        s.pop();
    }
    return answer;
}