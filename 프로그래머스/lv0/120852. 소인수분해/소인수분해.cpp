#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<int> tmp;
    for(int i=2; i<=n; i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
                tmp.emplace_back(i);
            }
        }
    }
    for(int i=0; i<tmp.size(); i++){
        if(i!=0 && tmp[i-1]==tmp[i]) continue;
        answer.emplace_back(tmp[i]);
    }
    return answer;
}