#include <bits/stdc++.h>
using namespace std;

string s;
long long ans=0;
stack<char> st;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    int sz=s.length();
    for(int i=0; i<sz; i++){
        if(s[i]=='(')
            st.push(s[i]);
        else{//')' 인 경우
            if(s[i-1]=='('){
                st.pop();
                ans+=st.size();
            }
            else{
                st.pop();
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}