#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end(),greater<int>());
    int st=0;
    int en=people.size()-1;
    while(st<en){
        if(people[st]+people[en]>limit){
            answer++;
            st++;
        }
        else {
            answer++;
            st++;
            en--;
        }
    }
    if(st==en) answer++;
    
    return answer;
}