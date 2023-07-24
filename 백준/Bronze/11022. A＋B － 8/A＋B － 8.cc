#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; 
    cin>>n;
    int i=0;
    while(n--){
        int a, b;
        i++;
        cin>>a>>b;
        cout<<"Case #"<<i<<": "<<a<<" + "<<b<<" = "<<a+b;
        cout<<'\n';
    }
}