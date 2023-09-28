#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num, int k) {
    int answer = 0;
    string s;
    s=to_string(num);
    char t='0'+k;
    for(int i=0; i<s.length();i++){
        if(s[i]==t){
            return i+1;
        }
    }
    return -1;
}