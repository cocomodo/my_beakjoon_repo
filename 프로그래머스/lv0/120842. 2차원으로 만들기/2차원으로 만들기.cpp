#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    int col = num_list.size()/n;
    int t=0;
    
    for(int i=1; i<=col; i++ ){
        vector<int> tmp;
        for(int j=0; j<n; j++){
            tmp.push_back(num_list[t]);
            t++;
        }
        answer.push_back(tmp);
    }
    return answer;
}