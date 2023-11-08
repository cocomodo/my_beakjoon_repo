#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> temp;
    for(int i=0; i<dungeons.size(); i++){
        temp.push_back(i);
    }
    do{
        int tmp=0;
        int tmpk=k;
        for(auto c: temp){ //이때 c 는 0 , 1, 2, 등의 수
            if(tmpk>=dungeons[c][0]){
                tmpk-=dungeons[c][1];
                tmp++;
                if(tmp==dungeons.size()) return tmp;
            } 
        }
        answer=max(answer,tmp);
    }while(next_permutation(temp.begin(),temp.end()));
    
    return answer;
}