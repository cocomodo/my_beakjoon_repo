#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    int x=0;
    int y=0;
    int limitx=board[0]/2;
    int limity=board[1]/2;
    for(auto str: keyinput){
        if(str=="left" && x-1>=-limitx){
            x--;
        }
        else if(str=="right"&& x+1<=limitx){
            x++;
        }else if(str=="up"&& y+1<=limity){
            y++;
        }else if(str=="down"&& y-1>=-limity){
            y--;
        }
    }
    answer.emplace_back(x);
    answer.emplace_back(y);
    return answer;
}