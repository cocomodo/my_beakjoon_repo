#include <bits/stdc++.h>

using namespace std;
int math3(vector<int>& v){
    int cnt=0;
    for(int i=0; i<v.size();i++){
        int a=i%10;
        switch(a){
            case 0: if(v[i]==3) cnt++;
                break;
            case 1: if(v[i]==3) cnt++;
                break;
            case 2: if(v[i]==1) cnt++;
                break;
            case 3: if(v[i]==1) cnt++;
                break;
            case 4: if(v[i]==2) cnt++;
                break;
            case 5: if(v[i]==2) cnt++;
                break;
            case 6: if(v[i]==4) cnt++;
                break;
            case 7: if(v[i]==4) cnt++;
                break;
            case 8: if(v[i]==5) cnt++;
                break;
            case 9: if(v[i]==5) cnt++;
                break;
        }
    }
    return cnt;
}
int math2(vector<int>& v){
    int cnt=0;
    for(int i=0; i<v.size();i++){
        int a=i%8;
        switch(a){
            case 0: if(v[i]==2) cnt++;
                break;
            case 1: if(v[i]==1) cnt++;
                break;
            case 2: if(v[i]==2) cnt++;
                break;
            case 3: if(v[i]==3) cnt++;
                break;
            case 4: if(v[i]==2) cnt++;
                break;
            case 5: if(v[i]==4) cnt++;
                break;
            case 6: if(v[i]==2) cnt++;
                break;
            case 7: if(v[i]==5) cnt++;
                break;
        }
    }
    return cnt;
}
int math1(vector<int>& v){
    int cnt=0;
    for(int i=0; i<v.size();i++){
        int a=i%5;
        switch(a){
            case 0: if(v[i]==1) cnt++;
                break;
            case 1: if(v[i]==2) cnt++;
                break;
            case 2: if(v[i]==3) cnt++;
                break;
            case 3: if(v[i]==4) cnt++;
                break;
            case 4: if(v[i]==5) cnt++;
                break;
        }
    }
    return cnt;
}

bool cmp(pair<int,int> p,pair<int,int> q){
    return p.first>q.first || p.second<q.second;
}
vector<int> solution(vector<int> v) {
    vector<int> answer;
    int a= math1(v);
    int b= math2(v);
    int c= math3(v);
    auto p = make_pair(a,1);
    auto q = make_pair(b,2);
    auto r = make_pair(c,3);
    vector<pair<int,int>> tmp;
    tmp.push_back(p);
    tmp.push_back(q);
    tmp.push_back(r);
    sort(tmp.begin(),tmp.end(),cmp);
    for(auto t: tmp){
        cout<<t.first<<" : "<<t.second<<'\n';
    }
    for(int i=0; i<tmp.size(); i++) {
        if(i==0) answer.push_back(tmp[i].second);
        else{
            if(tmp[i].first==tmp[0].first) answer.push_back(tmp[i].second);
        }
    }
    return answer;
}
/*
1 2 3 4 5  || 1 2 3 4 5 || ...
2 1 2 3 2 4 2 5 || 2 1 2 3 2 4 2 5 || ...
3 3 1 1 2 2 4 4 5 5 || 3 3 1 1 2 2 4 4 5 5 || ...
*/