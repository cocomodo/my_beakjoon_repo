#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer(prices.size(),0);
    vector<int> stack;

    for(int i = 0 ; i < prices.size() - 1; i++){
        if(stack.empty() || prices[i] >= prices[stack.back()]){
            stack.push_back(i);
        }
        else{
            while(!stack.empty() && prices[i] < prices[stack.back()]){
                stack.pop_back();
            }
            stack.push_back(i);
        }

        for(auto &x : stack){
            answer[x]++;
        }
    }

    return answer;
}