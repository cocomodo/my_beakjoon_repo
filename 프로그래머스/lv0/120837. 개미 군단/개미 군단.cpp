#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int a=5;
    int b=3;
    int c=1;
    int answer = 0;
    answer+=hp/a; hp%=a;
    answer+=hp/b; hp%=b;
    answer+=hp/c; hp%=c;
    return answer;
}