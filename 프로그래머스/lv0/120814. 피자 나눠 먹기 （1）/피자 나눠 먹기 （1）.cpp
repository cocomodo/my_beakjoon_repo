#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int a=n%7;
    int b=n/7;
    int c=n/7+1;
    // cout<< a<<"  "<<b<<"  "<<c;
    return a==0? b: c;
}