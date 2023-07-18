#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[15][15];
int n, st;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> comb;
    cin>>n>>st; //이때 st는 탐색을 시작하는 행성의 위치

    for(int i=0; i<n; i++)
        if(i!=st) comb.push_back(i);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>d[i][j];
        }
    }
    
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }

    int ans=0x7f7f7f7f;

    do{
        int tmp=d[st][comb[0]];// 첫번째 이동에 의한 이동거리 값
        for(int i=1; i<n-1;i++)
            tmp+=d[comb[i-1]][comb[i]];
        ans=min(tmp,ans);
    }while(next_permutation(comb.begin(),comb.end()));
    cout<<ans;
}