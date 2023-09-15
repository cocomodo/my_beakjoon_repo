#include <string>
#include <vector>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    for(auto c: a){
        if(c==b[0]) continue;
        answer+=c;
    }
    return answer;
}