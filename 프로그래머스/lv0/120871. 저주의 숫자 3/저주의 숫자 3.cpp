#include <string>
#include <vector>
#include <iostream>
using namespace std;

int a[105];
bool not3(int n){
    int tmp=0;
    while(n>0){
        tmp=n%10;
        if(tmp!=0 && tmp==3) return false;
        n/=10;
    }
    return true;
}
//3이 들어간 숫자도 사용하지 않는다. 3의 배수가 들어간 숫자를 사용하지 않는게 아니다. 주의
int solution(int n) {
    int answer = 0;
    int t=0; 
    for(int i=1; i<=105; i++){
        t++;
        while(t%3==0 || !not3(t)) t++;
        a[i]=t;
    }
    return a[n];
}