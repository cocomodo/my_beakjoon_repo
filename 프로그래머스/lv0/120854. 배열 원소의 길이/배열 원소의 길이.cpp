#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    for(auto c: strlist){
        answer.emplace_back(c.size());
    }
    return answer;
}