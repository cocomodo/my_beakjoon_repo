#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int t=sqrt(n);
    if(t*t==n) return 1;
    return 2;
}