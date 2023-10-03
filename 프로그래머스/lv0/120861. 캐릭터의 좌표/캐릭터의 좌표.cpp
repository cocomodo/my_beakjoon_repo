#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board)
{
    vector<int> v(2,0); // 좌우 상하
    for(string s : keyinput)
    {
        if     (s=="up"    && v[1]<+board[1]/2) v[1]++;
        else if(s=="down"  && v[1]>-board[1]/2) v[1]--;
        else if(s=="left"  && v[0]>-board[0]/2) v[0]--;
        else if(s=="right" && v[0]<+board[0]/2) v[0]++;
    }
    return v;
}