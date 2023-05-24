#include <bits/stdc++.h>
using namespace std;

int tmp;
int ans;
int sign=1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;

    for(char c: s){
        if(c=='+'||c=='-'){
            ans+=tmp*sign;
            if(c=='-') sign=-1;
            tmp=0;
        }else{
            tmp*=10;
            tmp+=c-'0';
        }
    }
    ans+=tmp*sign;//마지막 부호가 등장하고 난 뒤에 쌓인 tmp값을 저장해주는 과정
    cout<<ans;
}