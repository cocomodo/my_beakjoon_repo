#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    int num=numbers.size();
    cout<<(2*(k-1))%num;
    // if(k==1) answer=numbers[0];
    // else
    answer=numbers[(2*(k-1))%num];
    return answer;
}