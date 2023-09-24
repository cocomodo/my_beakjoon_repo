#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> stk;

int solution(string s) {
    int answer = 0;
    int plus=1;
    int tmp=0;
    for(auto c: s){
        if(isdigit(c)){
            tmp=tmp*10+c-'0';
        }
        else if(c=='-'){
            plus=-1;
        }
        else if(c==' '){
            stk.push(plus*tmp);
            plus=1;
            tmp=0;
        }
        else{//c=='Z'
            stk.pop();
        }
    }
    if(s[s.size()-1]!='Z') stk.push(plus*tmp);
    while(!stk.empty()){
        answer+=stk.top(); stk.pop();
    }
    
    return answer;
}