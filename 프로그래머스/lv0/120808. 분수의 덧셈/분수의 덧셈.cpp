#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    int a= numer1*denom2+numer2*denom1;
    int b=denom1*denom2;
    vector<int> answer={(a)/gcd(a,b), b/gcd(a,b)};
    return answer;
}