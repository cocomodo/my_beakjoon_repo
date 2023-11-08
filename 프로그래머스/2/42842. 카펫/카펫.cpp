#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    double a= (brown+4)/2; //a = x+y; 이때 x>=y;
    double b=brown+yellow; // b = x*y;
    // cout<<a<<" :a ||"<<b<<" :b "<<'\n';
    // cout<<a*a-4*b<<'\n';
    // cout<<a/2<<'\n';//a가 int로 선언되어 있으면, 이 값이 3.5가 아니라 3으로 연산된다.
    // cout<<sqrt(a*a-4*b)/2<<" :sqrt(a*a-4*b) 값"<<'\n';
    int x=sqrt(a*a-4*b)/2+a/2;
    int y=b/x;
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}
