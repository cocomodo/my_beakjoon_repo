#include <string>
#include <vector>

using namespace std;

int solution(int a) {
    if(a==180) return 4;
    else if(a>90) return 3;
    else if(a==90) return 2;
    else return 1;
}