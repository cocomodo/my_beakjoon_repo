#include <string>
#include <vector>

using namespace std;

string solution(string str, int num1, int num2) {
    string answer = "";
    swap(str[num1],str[num2]);
    answer=str;
    return answer;
}