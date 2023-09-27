#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    for(auto c: s1){
        for(auto s: s2){
            if(c==s) answer++;
        }
    }
    return answer;
}