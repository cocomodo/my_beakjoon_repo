#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int a= common[0];
    int b= common[1];
    int c= common[2];
    int len=common.size();
    int last=len-1;
    if(a+c==2*b) return 2*common[last]-common[last-1]; 
    else return common[last]*common[last]/common[last-1];
}