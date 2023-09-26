#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    vector<char> v;
    string tmp;
    string num;
    for(auto c: numbers){
        tmp+=c;
        if(tmp=="one"){
            tmp="";
            num+='1';
        }
        else if(tmp=="two") {
            tmp="";
            num+='2';    
        }else if(tmp=="three") {
            tmp="";
            num+='3';    
        }else if(tmp=="four") {
            tmp="";
            num+='4';    
        }else if(tmp=="five") {
            tmp="";
            num+='5';    
        }else if(tmp=="six") {
            tmp="";
            num+='6';    
        }else if(tmp=="seven") {
            tmp="";
            num+='7';    
        }else if(tmp=="eight") {
            tmp="";
            num+='8';    
        }else if(tmp=="nine") {
            tmp="";
            num+='9';    
        }else if(tmp=="zero") {
            tmp="";
            num+='0';    
        }
    }
    answer=stoll(num);
    return answer;
}