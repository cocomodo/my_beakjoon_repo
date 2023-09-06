#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        string init;
        cin>>init;
        list<char> L={};
        auto cursor=L.end();
        for(auto c: init){
            if(c=='<'){
                if(cursor!=L.begin()) cursor--;
            }
            else if(c=='>'){
                if(cursor!=L.end()) cursor++;
            }
            else if(c=='-'){
                if(cursor!=L.begin()){
                    cursor--;
                    cursor=L.erase(cursor);
                }
            }
            else{ //글자일때,
                L.insert(cursor,c);
            }
        }
        for(auto c: L){
            cout<<c;
        }
        cout<<'\n';
    }
}