#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int size=commands.size();
    for(int i=0; i<size; i++){
        vector<int> sub_v;
        int st=commands[i][0]-1;
        int en=commands[i][1]-1;
        for(st; st<=en; st++){
            sub_v.push_back(array[st]);
        }
        sort(sub_v.begin(),sub_v.end());
        answer.push_back(sub_v[commands[i][2]-1]);
    }
    return answer;
}