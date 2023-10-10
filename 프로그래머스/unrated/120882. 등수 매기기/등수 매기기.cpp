#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    vector<int> tmp;
    vector<int> mid;
    for(auto t: score){
        tmp.push_back((t[0]+t[1]));
        mid.push_back((t[0]+t[1]));
    }
    pair<int,int> a[15]={};
    sort(tmp.begin(),tmp.end(),greater<>());
    for(int i=0; i<tmp.size();i++){
        if(i!=0 && (tmp[i]==a[i-1].second)) {
            a[i]={a[i-1].first,tmp[i]};     
        }
        else a[i]={i+1,tmp[i]};
    }
    for(auto c: mid){
        for(int i=0; i<mid.size();i++){
            if(c==a[i].second){
                answer.push_back(a[i].first);               
                break;
            }    
        }
    }
    return answer;
}