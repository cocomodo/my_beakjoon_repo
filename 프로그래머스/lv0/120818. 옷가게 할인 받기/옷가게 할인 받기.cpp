#include <string>
#include <vector>

using namespace std;

int solution(int a) {
    int answer = 0;
    if(a>=100'000 && a<300'000)
        a*=0.95;
    else if(a>=300'000 && a<500'000)
        a*=0.9;
    else if(a>=500'000)
        a*=0.8;
    return a;
}