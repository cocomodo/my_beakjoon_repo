#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string str) {
    string answer = "";
    // cout<<int('a')<<' '<<int('z')<<' '<<int('A')<<' '<<int('Z');
    for(auto c: str){
        if(c>=97 && c<=122) answer+=char(c-32);
        else answer+=char(c+32);
    }
    return answer;
}