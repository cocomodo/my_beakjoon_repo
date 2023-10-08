#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b) {
    //최대공약수를 이용해서 b를 나누고, b의 소인수가 2와 5만 있는지 확인하면 될듯
    int t=gcd(a,b);
    int chk=b/t;
    
    while(chk%2==0 || chk%5==0){
        if(chk%2==0) chk/=2;
        if(chk%5==0) chk/=5;
    }
    if(chk==1) return 1;
    return 2;
}