#include <bits/stdc++.h>
using namespace std;

int n;
int a[1'000'005];
vector<int> tmp, uni;//unique
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        tmp.push_back(a[i]);
    }
    sort(tmp.begin(),tmp.end());
    for(int i=0; i<n; i++){
        if(i==0||tmp[i-1]!=tmp[i])
            uni.push_back(tmp[i]);
    }
    for(int i=0; i<n; i++){
        cout<<lower_bound(uni.begin(),uni.end(),a[i])-uni.begin()<<' ';
        //lower_bound는 배열이면 포인터를, vector면 iterator를 반환하기 때문에 이런식으로 
        //처리를 해줘서 index를 반환시킨다.  
    }

}