#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    return n*12'000+(k-n/10)*2'000;
}