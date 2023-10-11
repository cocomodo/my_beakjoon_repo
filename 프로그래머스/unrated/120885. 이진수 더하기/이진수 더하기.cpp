#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int ten(int n){
    int i=0;
    int num =0;
    while(n>0){
        int c= (n%10)*pow(2,i);
        n/=10;
        num+=c; 
        i++;
    }
    return num;
}

string binary(int n){
    string num="";
    if(n==0) return "0";
    while(n>0){
        num+=to_string(n%2);    
        n/=2;
    }
    reverse(num.begin(),num.end());
    return num;
}

string solution(string bin1, string bin2) {
    string answer = "";
    int a= stoi(bin1);
    int b= stoi(bin2);
    int c= ten(a)+ten(b);
    answer=binary(c);
    return answer;
}