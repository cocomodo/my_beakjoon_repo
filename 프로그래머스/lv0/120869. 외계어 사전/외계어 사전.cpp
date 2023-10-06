#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    // cout<<int('a')<<"  "<<int('z');
    int answer = 0;
    int dlen=dic.size();
    int slen=spell.size();
    for(int i=0; i<dlen; i++){
        int chk[200]={0}; 
        for(auto c: dic[i]){
            chk[c]++;
        }
        bool possible=true;
        for(auto d: spell){
            if(chk[d[0]]==0) possible=false;
        }
        if(possible) return 1;
    }
    return 2;
}