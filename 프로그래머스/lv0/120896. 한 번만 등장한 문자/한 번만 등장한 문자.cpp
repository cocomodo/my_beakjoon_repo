#include <string>
#include <vector>
#include <iostream>
using namespace std;
int a[200];

string solution(string s) {
    string answer = "";
    cout<<int('a')<<' '<<int('z');
    for(auto c:s){
        a[int(c)]++;
    }
    for(int i=97;i<=122;i++){
        if(a[i]!=1) continue;
        answer+=char(i);
    }
    return answer;
}