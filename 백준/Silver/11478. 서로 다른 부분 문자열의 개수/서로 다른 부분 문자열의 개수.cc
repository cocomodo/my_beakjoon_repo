#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    unordered_set<string> uset;
    for(int st=0; st<s.length();st++){
        for(int len=1; st+len<=s.length();len++){
            uset.insert(s.substr(st,len));
        }
    }
    cout<<uset.size();
}