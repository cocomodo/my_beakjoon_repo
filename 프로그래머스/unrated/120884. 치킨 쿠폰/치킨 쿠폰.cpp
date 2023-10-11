#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    int cp=chicken; //1081 일시에
    int service=0;
    
    while(cp>=10){
        service=cp/10;
        answer+=service;
        cp=service+cp%10;
    }
    return answer;
}