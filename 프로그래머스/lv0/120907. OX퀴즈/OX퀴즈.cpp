#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for(auto s: quiz){
        cout<<"h"<<'\n';
        stringstream ss;
        ss.str(s);
        int num1=0;
        int num2=0;
        char op;
        char equal;
        int num3=0;
        ss>>num1>>op>>num2>>equal>>num3;
        if(op=='+'){
            if(num1+num2==num3) answer.emplace_back("O");
            else answer.emplace_back("X");
        }
        else{
            if(num1-num2==num3) answer.emplace_back("O");
            else answer.emplace_back("X");
        }
    }
    return answer;
}