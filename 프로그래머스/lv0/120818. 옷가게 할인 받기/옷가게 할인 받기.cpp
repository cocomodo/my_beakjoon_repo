#include <string>
#include <vector>

using namespace std;

int solution(int a) {
    if(a>=500'000)
        a*=0.8;
    else if(a>=300'000)
        a*=0.9;
    else if(a>=100'000)
        a*=0.95;
    return a;
}