#include <string>
#include <vector>

using namespace std;

int solution(string str) {
    int answer = 0;
    int sign=1;
    vector<int> v;
    string tmp;
    for(auto c: str){
        if(c==' '){
            if(tmp!=""){
                v.emplace_back(sign*stoi(tmp));
                tmp="";    
            }  
        }
        else if(c=='-'){
            sign=-1;
        }
        else if(c=='+'){
            sign=1;
        }
        else{ //그냥 글자일때
            tmp+=c;
        }
    }
    v.emplace_back(sign*stoi(tmp));
    for(auto c: v) answer+=c;
    return answer;
}