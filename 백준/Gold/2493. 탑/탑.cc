#include <bits/stdc++.h>
using namespace std;

int n;
stack<pair<int,int>> tower;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    tower.push({100'000'005,0});
    for(int i=1; i<=n; i++){
        int h;
        cin>>h;
        while(tower.top().first<=h){
            tower.pop();
        }
        cout<<tower.top().second<<' ';
        tower.push({h,i});
    }
}