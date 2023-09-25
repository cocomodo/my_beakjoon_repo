#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    vector<pair<int,int>> v;
    for(auto c: array){
        v.push_back({abs(n-c),c});
    }
    sort(v.begin(),v.end());
    answer=v[0].second;
    return answer;
}