#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    reverse(s.begin(),s.end());    
    return s;
}