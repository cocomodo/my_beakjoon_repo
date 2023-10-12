#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    for(int t=i; t<=j; t++){
        int q=t;
        int p=0;
        while(q>0){
            p=q%10;
            if(p==k) answer++;
            q/=10;
        }
    }
    return answer;
}