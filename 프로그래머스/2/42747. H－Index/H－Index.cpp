#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> v) {
    int answer = 0;
    for(int i=v.size();i>=0;i--){
        int cnt=0;
        for(auto t: v) {
            if(t>=i) cnt++; 
        }
        if(cnt>=i) answer=max(answer,i);
    }
    return answer;
}
//6편의 논문은, 5편의 논문은, 4편의 논문은 등등등.. 테스트 해보면서 내리자. 