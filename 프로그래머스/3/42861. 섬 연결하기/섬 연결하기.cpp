#include <bits/stdc++.h>

using namespace std;

int sets[101];

int getParent(int x){
    if(sets[x]==x) return x;
    sets[x]=getParent(sets[x]);
    return sets[x];
    //return sets[x]=getParent(sets[x]); 로 작성해도 된다. 
}

bool cmp(vector<int> a, vector<int> b){
    return a[2]<b[2];
}

int solution(int n , vector<vector<int>> costs){
    int answer=0;
    
    for(int i=0; i<n; i++)
        sets[i]=i;
    
    sort(costs.begin(),costs.end(),cmp);
    
    for(int i=0; i<costs.size(); i++){
        int start = getParent(costs[i][0]);
        int end= getParent(costs[i][1]);
        int cost=costs[i][2];
        
        if(start!=end){
            answer+=cost;
            sets[end]=start;
        }
    }
    return answer;
}