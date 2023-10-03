#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    vector<int> xv;
    vector<int> yv;
    xv.push_back(dots[0][0]);
    xv.push_back(dots[1][0]);
    xv.push_back(dots[2][0]);
    xv.push_back(dots[3][0]);
    int x=*max_element(xv.begin(),xv.end())-*min_element(xv.begin(),xv.end());
    yv.push_back(dots[0][1]);
    yv.push_back(dots[1][1]);
    yv.push_back(dots[2][1]);
    yv.push_back(dots[3][1]);
    int y=*max_element(yv.begin(),yv.end())-*min_element(yv.begin(),yv.end());
    answer=x*y;
    answer=x*y;
    return answer;
}