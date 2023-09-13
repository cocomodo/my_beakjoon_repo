#include <string>
#include <vector>

using namespace std;

int a[1000];

int solution(vector<int> v) {

    for(auto c: v){
        a[c]++;
    }
    int mx=-1;
    for(auto b: a){
        mx=max(mx,b);
    }
    int cnt=0;
    for(auto d:a){
        if(d==mx) cnt++; 
    }
    int answer=0;
    for(int i=0; i<1000; i++){
        if(mx==a[i]) answer=i;
    }
    if(cnt==1) return answer;
    else return -1;

}