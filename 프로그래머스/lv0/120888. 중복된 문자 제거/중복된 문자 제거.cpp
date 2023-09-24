#include <string>
#include <vector>

using namespace std;

int a[200];

string solution(string str) {
    string answer = "";
    for(auto c: str){
        if(a[int(c)]==1) continue;
        answer+=c;
        a[int(c)]=1;
    }
    return answer;
}