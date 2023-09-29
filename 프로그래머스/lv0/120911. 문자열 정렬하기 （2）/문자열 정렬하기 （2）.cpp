#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string str) {
    for(auto& c: str){
        if(c>=65&&c<=90) c+=32;
    }
    cout<<str;
    sort(str.begin(),str.end());
    return str;
}