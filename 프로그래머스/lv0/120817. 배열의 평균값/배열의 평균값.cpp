#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    for(auto c: numbers){
        answer+=c;
    }
    answer/=numbers.size();
    return answer;
}