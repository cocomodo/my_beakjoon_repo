#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i=0; i<prices.size()-1;i++){
        int cnt=0;
        for(int j=i+1; j<prices.size(); j++){
            cnt++;
            if(prices[i]>prices[j]) {
                answer.push_back(cnt);
                break;
            }
            if(cnt==prices.size()-1-i) answer.push_back(cnt);
        }
    }
    answer.push_back(0);
    
    return answer;
}