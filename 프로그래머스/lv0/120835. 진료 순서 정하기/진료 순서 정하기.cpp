#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector<int> duple(emergency.begin(),emergency.end());
    sort(duple.begin(),duple.end(),greater<int>());
    for(int i=0; i<emergency.size(); i++){
        for(int j=0; j<emergency.size(); j++){
            if(emergency[i]==duple[j]) answer.emplace_back(j+1);
        }
    }
 
    return answer;
}