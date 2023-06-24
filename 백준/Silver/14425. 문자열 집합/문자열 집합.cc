#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    set<string> wordSet;
    int cnt=0;
    while(n--){
        string setS;
        cin>>setS;
        wordSet.insert(setS);
    }
    while(m--){
        string query;
        cin>>query;
        if(wordSet.find(query)!=wordSet.end()){
            cnt++;
        }
    }
    cout<<cnt;
}