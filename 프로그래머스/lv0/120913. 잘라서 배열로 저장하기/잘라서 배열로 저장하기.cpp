#include <string>
#include <vector>

using namespace std;

vector<string> solution(string str, int n) {
    vector<string> answer;
    for(int i=0; i<str.length();i+=n){
        string tmp="";
        for(int j=0; j<n; j++){
            if(i+j>=str.length()) continue;
            tmp+=str[i+j];
        }
        answer.emplace_back(tmp);
    }
    return answer;
}