#include <bits/stdc++.h>

using namespace std;

int d[505][505];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n=triangle.size();
    d[1][1]=triangle[0][0];
    for(int i=2; i<=n; i++)
        for(int j=1; j<=i; j++)
            d[i][j]=max(d[i-1][j-1],d[i-1][j]) +triangle[i-1][j-1];//d[i-1][0] 의 경우 0
    answer=*max_element(d[n]+1,d[n]+n+1);
    return answer;
}