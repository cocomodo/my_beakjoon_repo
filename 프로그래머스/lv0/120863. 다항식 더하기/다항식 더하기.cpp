#include <string>
#include <vector>
#include <iostream>

//'0' 의 값은 48, '1'의 값은 49, '9'의 값은 57
using namespace std;

string solution(string str) {
    string answer = "";
    int len=str.length();
    long long tmp=0;
    long long tx=0;
    long long tc=0;
    //결국, 숫자야? x야? ' '(공백) 이야?, '+'야? 라는 네가지가 있고, +의 경우 무시해도 되고, 맨 마지막은 공백이 없다.
    for(int i=0; i<len; i++){
        if(str[i]>='0'&& str[i]<='9'){
            tmp*=10;
            tmp+=(str[i]-'0'); //tmp값에 수를 저장.
        }
        else if(str[i]=='x'){
            if(i!=0 && str[i-1]!=' '){
                tx+=tmp;
                tmp=0;
            }
            if(i!=0 && str[i-1]==' ') tx++;
            if(i==0) tx++;
        }
        else if(str[i]==' '){
            if((i!=0 && str[i-1]!='x') || (i!=0 && str[i-1]!='+')){
                tc+=tmp;
                tmp=0;    
            }
        }
    }
    if(tmp!=0){
        tc+=tmp;
        tmp=0;
    }
    // cout<<tx<< "  "<<tc;
    if(tx!=0){
        if(tx!=1)
            answer+=to_string(tx);
        answer+='x';    
    }
    if(tx!=0 && tc!=0) answer+=" + ";
    if(tc!=0){
        answer+=to_string(tc);
    }
    return answer;
}