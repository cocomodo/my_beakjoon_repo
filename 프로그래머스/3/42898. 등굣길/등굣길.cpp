#include <bits/stdc++.h>

using namespace std;

bool water[105][105];
int dp[105][105];
int mod=1'000'000'007;

int solution(int m, int n, vector<vector<int>> v) {
    int answer = 0;
    
    for(int i=0; i<v.size(); i++){
        int x = v[i][0];
        int y = v[i][1];
        water[x][y]=true;
    }
    dp[1][1]=1;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(water[i][j]==true) continue;
            if(i-1>=1) dp[i][j] += dp[i-1][j];
            if(j-1>=1) dp[i][j] += dp[i][j-1];
            dp[i][j]%=mod;
        }
    }
    answer=dp[m][n];
    
    return answer;
}