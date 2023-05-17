#include <bits/stdc++.h>
using namespace std;

int freq[2'000'001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        freq[a+1'000'000]++;
    }
    for(int i=0; i<=2'000'000;i++){
        while(freq[i]--)
            cout<<i-1'000'000<<'\n';
    }
}