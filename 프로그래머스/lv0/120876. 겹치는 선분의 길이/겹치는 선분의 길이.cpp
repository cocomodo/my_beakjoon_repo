#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    int a[210]={};
    for(auto t:lines){
        int st=t[0];
        int en=t[1]; // st<en 이 보장됨.
        for(int i=st; i<=en;i++){
            a[i+100]++;
        }
    }
    int tmp=-1;
    for(int j=0; j<210; j++){
        if(a[j]>=2) tmp++;
        else {
            if(tmp>=0) answer+=tmp;
            tmp=-1;
        }
    }
    sort(lines.begin(),lines.end());
    if((lines[1][1]-lines[1][0]==1)&& (lines[0][1]==lines[1][0]&&lines[1][1]==lines[2][0])) answer--;
    return answer;
}