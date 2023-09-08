#include <bits/stdc++.h>
using namespace std;

void parse(string& tmp, deque<int>& d){
    int cur=0;
    for(int i=1; i+1<tmp.size(); i++){ //이렇게 해서 '['과 ']' 를 안받아들이는구나
        if(tmp[i]==','){
            d.push_back(cur);
            cur=0;
        }
        else{
            cur=10*cur+(tmp[i]-'0');
        }
    }
    if(cur!=0)
        d.push_back(cur);
}

void print_result(deque<int>& d){
    cout<<'[';
    for(int i=0; i<d.size(); i++){
        cout<<d[i];
        if(i+1!=d.size())
            cout<<',';
    }
    cout<<"]\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        deque<int> d;
        int rev=0;
        int n;
        bool isWrong=false;
        string query, tmp;
        cin>>query;
        cin>>n;
        cin>>tmp;
        parse(tmp,d);
        for(char c: query){
            if(c=='R') //bool isReversed 을 정의해서 true false를 바꾸어도 된다 
                rev=1-rev;
            else{
                if(d.empty()){
                    isWrong=true;
                    break;
                }
                if(!rev) d.pop_front();
                else d.pop_back();
            }
        }
        if(isWrong)
            cout<<"error\n";
        else{
            if(rev) reverse(d.begin(),d.end()); //출력하기전에 마지막에 rev가 참이면 한번 뒤집어준다. 
            print_result(d);
        }
    }
}