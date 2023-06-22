#include <bits/stdc++.h>
using namespace std;

int ttoi(string time){
    int t=0;
    string h, m;
    h=time.substr(0,2);
    m=time.substr(3,2);
    
    t=(60*stoi(h))+stoi(m);
    return t;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int cnt=0;

    string S,E,Q;
    cin>>S>>E>>Q;

    int st_t, end_t, stream_t;
    st_t=ttoi(S);
    end_t=ttoi(E);
    stream_t=ttoi(Q);

    unordered_set<string> st_list;
    unordered_set<string> atd_list;

    while(true){
        string c_time,name;
        cin>>c_time>>name;
        if(cin.eof()==true) break;
        if(ttoi(c_time)<=st_t){
            st_list.insert(name);
        }
        else if(ttoi(c_time)>=end_t && ttoi(c_time)<=stream_t){
            if(st_list.find(name)!=st_list.end()){/*위와 같은 조건을 만족하는데,
            그 조건을 만족하는 것이 st_list에 있다면, atd_list에 담는다.*/
                atd_list.insert(name);
            }
        }
    }
    cout<<atd_list.size()<<'\n';
}