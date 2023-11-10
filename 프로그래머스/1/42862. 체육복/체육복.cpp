#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> num(n+1);
    fill(num.begin(),num.end(),1);
    for(auto t: lost) num[t]-=1;
    for(auto t: reserve) num[t]+=1;
    for(int i=1; i<=n; i++){
        if(num[i]==0){
            if(i==1&&num[i+1]==2){
                num[i]+=1;
                num[i+1]-=1;
            }
            else if(i==n&&num[i-1]==2){
                num[i]+=1;
                num[i-1]-=1;
            }
            else if(i!=1 && i!=n){
                if(num[i-1]==2) {
                    num[i-1]-=1;
                    num[i]+=1;
                }
                else if(num[i+1]==2){
                    num[i+1]-=1;
                    num[i]+=1;
                }
            }
        }
    }
    for(int i=1; i<=n; i++) if(num[i]>=1) answer++;
    
    return answer;
}