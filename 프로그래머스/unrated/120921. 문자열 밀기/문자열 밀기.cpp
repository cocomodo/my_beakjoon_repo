#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string A, string B) {
    int answer = 0;
    if(A==B) return 0;
    int len=A.length();
    bool pos=false;
    for(int i=0 ;i<len-1;i++){ // len-1 로 작성해야 tmp가 제자리로 돌아오지 않고 하나 부족한 상태로 종료. 
        string tmp;
        //아래 과정을 거치면 1회 밀기 완료.
        tmp+=A[len-1];
        for(int i=0; i<len-1; i++){
            tmp+=A[i];
        }
        A=tmp;
        if(tmp==B){
            answer=i+1;
            pos=true;
            break;
        } 
    }
    if(pos==false) return -1;
    return answer;
}