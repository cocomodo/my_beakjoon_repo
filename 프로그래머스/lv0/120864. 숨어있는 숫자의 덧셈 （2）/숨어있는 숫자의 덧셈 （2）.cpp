#include <string>
#include <vector>
#include <cctype>
//isdigit() 함수 사용하기 위해 cctype 헤더 포함
using namespace std;

int solution(string str) {
    int answer = 0;
    int tmp=0;
    for(auto c: str){
        if(isdigit(c)) {
            tmp*=10;
            tmp+=c-'0';
        }else{
            if(tmp!=0){
                answer+=tmp;
                tmp=0;
            }
        }
    }
    if(tmp!=0) answer+=tmp;
    return answer;
}