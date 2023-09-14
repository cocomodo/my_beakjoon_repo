#include <bits/stdc++.h>
using namespace std;

stack<char> s;
string str;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>str;
    int sum=0;//누적해서 더해질 값
    int num=1; //곱해질 값
    
    for(int i=0; i<str.size(); i++){
        if(str[i]=='('){
            num*=2; //소괄호가 나오면 곱해질 값 2배 증가
            s.push(str[i]);
        }
        else if(str[i]=='['){
            num*=3; //대괄호가 나오면 곱해질 값 3배 증가
            s.push(str[i]);
        }
        else if(str[i]==')'){
            if(s.empty()||s.top()!='('){
                cout<<0;
                return 0;
            }
            if(str[i-1]=='(') sum+=num;
            s.pop();
            num/=2;
        }
        else{ // str[i] ==']'
            if(s.empty() || s.top()!='['){
                cout<<0;
                return 0;
            } 
            if(str[i-1]=='[') sum+=num;
            s.pop();
            num/=3;
        }
    }
    if(s.empty()) cout<<sum;
    else cout<<0;
}