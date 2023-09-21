#include <string>
#include <vector>

using namespace std;
int factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else
        return n*factorial(n-1);
}
int solution(int n) {
    int i = 0;
    while(factorial(i) <= n)
        i++;
    i--;
    return i;
}