#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    vector<int> arr(201,0);

    int answer = 0;
    for(auto& v : lines){
        for(int i = v[0]; i < v[1]; ++i){
            arr[i+100]++;
        }
    }
    for(const auto v : arr){
        answer += v > 1;
    }
    return answer;
}