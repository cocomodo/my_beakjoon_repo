#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for(int i=0; i<babbling.size(); i++){
        int len= babbling[i].size();
        bool pos=true;
        for(int j=0; j<len; j++){
            if(babbling[i][j]=='a'){ //"aya"
                if((j+2<len)&&babbling[i][j+1]=='y'&&babbling[i][j+2]=='a') {j+=2;}
                else{
                    pos = false;
                }
            }
            else if(babbling[i][j]=='y'){ //"ye"
                if((j+1<len)&& babbling[i][j+1]=='e') {j++;}
                else{
                    pos = false;
                }
            }
            else if(babbling[i][j]=='w'){ //"woo"
                if((j+2<len)&&babbling[i][j+1]=='o'&&babbling[i][j+2]=='o') {j+=2;}
                else{
                    pos = false;
                }
            }
            else if(babbling[i][j]=='m'){ //"ma"
                if((j+1<len)&&babbling[i][j+1]=='a') {j++;}
                else{
                    pos = false;
                }
            }
            else{ //그외 나머지.
                pos=false;
            }
        }
        if(pos) answer++;
    }
    return answer;
}