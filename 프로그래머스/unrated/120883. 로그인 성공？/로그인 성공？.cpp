#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    bool pos=false;
    for(auto c: db){
        if(id_pw[0]==c[0]&& id_pw[1]==c[1]) {
            return "login";
        }
        else if(id_pw[0]==c[0]&& id_pw[1]!=c[1]) {
            return "wrong pw";
        }
    }
    if (!pos) answer="fail";
    return answer;
}