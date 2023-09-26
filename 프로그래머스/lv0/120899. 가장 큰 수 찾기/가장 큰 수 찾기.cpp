#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    auto it=max_element(array.begin(),array.end());
    // cout<<it-array.begin();
    answer.emplace_back(*it);
    answer.emplace_back(it-array.begin());
    return answer;
}