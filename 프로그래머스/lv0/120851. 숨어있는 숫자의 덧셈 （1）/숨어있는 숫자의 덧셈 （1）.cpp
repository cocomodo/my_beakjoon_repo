#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string str) {
    int answer = 0;
    for(auto c:str){
        if(isdigit(c)) answer+=c-'0';
    }
    return answer;
}