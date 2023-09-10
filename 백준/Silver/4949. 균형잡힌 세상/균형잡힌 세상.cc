#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true){
        string a;
        getline(cin,a);
        stack<char> s;
        bool isValid=true;
        if(a==".") break;
        for(auto c: a){
            if(c=='('||c=='[') s.push(c);
            else if(c==')'){
                if(s.empty()||s.top()!='('){
                    isValid=false;
                    break;
                }
                else s.pop();
            } 
            else if(c==']'){
                if(s.empty()|| s.top()!='['){
                    isValid=false;
                    break;
                }
                else s.pop();
            }
        }
        if(!s.empty()) isValid=false;
        if(isValid) cout<<"yes\n";
        else cout<<"no\n";
    }  
}