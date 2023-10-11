#include <string>
#include <vector>
#include <iostream>

using namespace std;

int a[200];
int b[200];
int solution(string before, string after) {
    for(auto c: before) a[c]++;
    for(auto c: after) b[c]++;

    for(auto c: before){
        if(a[c]!=b[c]) return 0;
    }
    
    return 1;
}