#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    int mx=-1;
    int idx=0;
    for(int i=0; i<array.size(); i++){
        if(mx<array[i]){
            mx=array[i];
            idx=i;
        }
    }
    answer.emplace_back(mx);
    answer.emplace_back(idx);
    return answer;
}
