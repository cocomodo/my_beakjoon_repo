#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    sort(numbers.begin(),numbers.end());
    if(numbers.size()==2){
        answer=numbers[0]*numbers[1];
    }
    else{
        int tmp1=numbers[numbers.size()-1]*numbers[numbers.size()-2];
        int tmp2=numbers[0]*numbers[1];
        answer=max(tmp1,tmp2);
    }
    return answer;
}