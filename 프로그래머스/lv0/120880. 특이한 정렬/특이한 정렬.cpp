#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool customCompare(pair<int,int> a, pair<int,int> b, int n){
    if(a.second == b.second){
        return a.first> b.first;
    }
    return abs(a.first-n)<abs(b.first-n);
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    vector<pair<int,int>> a;
    int len=numlist.size();
    for(int i=0; i<len; i++){
        a.push_back({numlist[i],abs(n-numlist[i])});
    }
    sort(a.begin(),a.end(),[n](pair<int,int> a, pair<int,int> b){
        return customCompare(a,b,n);
    });
    for(auto c: a){
        answer.emplace_back(c.first);
    }
    return answer;
}