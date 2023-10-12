#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    
    int tmp=total/num;
    int a= tmp - (num%2==0? (num/2-1) :num/2);
    int i=0; 
    while(num--){
        answer.emplace_back(a+i);
        i++;
    }
    return answer;
}