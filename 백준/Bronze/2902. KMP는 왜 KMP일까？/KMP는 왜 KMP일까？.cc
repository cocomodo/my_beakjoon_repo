#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    for(int i=0; i<s.length();i++){
        if(i==0) cout<<s[i];
        else{
            if(s[i-1]=='-') cout<<s[i];
        }
    }
}