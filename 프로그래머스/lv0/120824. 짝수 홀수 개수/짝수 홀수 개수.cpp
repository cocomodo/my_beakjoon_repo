#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> v) {
    int e=0;
    int o=0;
    for(auto c:v){
        if(c%2==0) e++;
        else o++;
    }
    vector<int> answer={e,o};
    return answer;
}