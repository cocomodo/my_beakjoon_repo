#include <bits/stdc++.h>

using namespace std;

int answer=0x7f7f7f7f;
vector<bool> vis(101);

void dfs(int idx, vector<vector<int>> wires){
    vis[idx]=true;
    for(int i=0; i<wires.size();i++){
        if(wires[i][0]==idx&&!vis[wires[i][1]]) dfs(wires[i][1],wires);
        else if(wires[i][1]==idx&&!vis[wires[i][0]]) dfs(wires[i][0],wires);
    }
}

int solution(int n, vector<vector<int>> wires){
    for(int i=0; i<wires.size();i++){
        int res=0;
        vector<vector<int>> tmp(wires);
        fill(vis.begin(),vis.end(),false);
        tmp.erase(tmp.begin()+i);
        dfs(tmp[0][0],tmp);
        for(int i=1; i<=n; i++){
            if(vis[i]) res++;
        }
        answer=min(answer,abs(res-(n-res)));
    }
    return answer;
}