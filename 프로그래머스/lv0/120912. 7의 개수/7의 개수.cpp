#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for(auto c: array){
        int t=0;
        while(c>0){
            t=c%10;
            if(t==7) answer++;
            c/=10;
        }
    }
    return answer;
}