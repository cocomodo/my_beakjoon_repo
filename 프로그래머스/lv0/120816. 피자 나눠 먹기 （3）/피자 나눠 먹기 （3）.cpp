#include <string>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

int solution(int slice, int n) {


    return n%slice==0?  n/slice : n/slice+1;
}