#include <string>
#include <vector>

using namespace std;

int d[11];

int solution(int n) {
    int answer = 0;
    d[1]=1;
    for(int i=2; i<=10;i++){
        d[i]=d[i-1]*i;
    }
    for(int i=1; i<=10; i++){
        if(n>=d[i]) answer=i;
    }
    return answer;
}