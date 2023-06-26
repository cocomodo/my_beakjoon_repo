#include <bits/stdc++.h>
using namespace std;

int N, Q, tmp, curr=1; 
set<int> hu;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>Q;
    for(int i=1; i<=N; i++){ //문제 자체가 1-indexed여서 1로 시작.
        cin>>tmp;
        if(tmp) hu.insert(i);
    }

    while(Q--){
        cin>>tmp;
        switch(tmp){
            case 1:
                cin>>tmp;
                if(hu.find(tmp)!=hu.end()){
                    hu.erase(tmp);
                }
                else{//명소가 아니었다면.
                    hu.insert(tmp);
                }
                break;
            case 2:
                cin>>tmp;
                curr=(curr-1+tmp)% N +1;
                break;
            case 3:
                if(hu.empty()) cout<<-1<<'\n';
                else{
                    if(hu.lower_bound(curr)!=hu.end()){
                        auto it=hu.lower_bound(curr);
                        cout<<*it-curr<<'\n';
                    }
                    else {//hu.lower_bound(curr)==hu.end()인 경우. 즉 curr 보다 뒤쪽에 명소가 있을때.
                        cout<<N-curr+*hu.begin()<<'\n';
                    }
                }
                break;
        }
    }
}