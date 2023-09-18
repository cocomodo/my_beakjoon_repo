#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

//parser 함수를 만들어서 위에 선언하고, 그 parser함수를 이용해서 solution 함수 내부에서
//수들을 나누어서 한번 string에 붙여보자. 

vector<int> parser(int age){
    vector<int> parsed;
    int num=age;
    while(num){
        parsed.emplace_back(num%10);
        num/=10;
    }
    reverse(parsed.begin(),parsed.end());
    // for(auto c: parsed) cout<<c<<' ';
    
    return parsed;
}

string solution(int age) {
    string answer = "";
    
    vector<int> v = parser(age);
    for(auto c: v){
        answer+=char(c+97);
    }
    // cout<<int('a')<<" 인트확인";
    return answer;
}