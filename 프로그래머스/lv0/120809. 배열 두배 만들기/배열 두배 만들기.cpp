#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i=0; i<numbers.size(); i++){
        answer.push_back(2*numbers[i]);
    }
    return answer;
}