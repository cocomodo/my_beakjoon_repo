#include <bits/stdc++.h>
using namespace std;

int ans;

void seqSum(vector<int> v){
    while(1<v.size()){
        ans+=*(v.end()-1)*(*(v.end()-2));
        v.pop_back();
        v.pop_back();
    }
    if(v.size()==1) ans+=v[0];
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<int> seqP;
    vector<int> seqN;
    while(n--){
        int t;
        cin>>t;
        if(t==1) ans+=1;
        else if(t>1) //
            seqP.push_back(t);
        else
            seqN.push_back(t); 
    }
    sort(seqP.begin(),seqP.end());
    sort(seqN.begin(),seqN.end(),greater<>());
    seqSum(seqP);
    seqSum(seqN);
    cout<<ans;
}