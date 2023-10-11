#include <string>
#include <vector>

using namespace std;

int result = 0;

int solution(int chicken) {
    
    int numOfTck = chicken;
    int serviceChicken;
    
    while (numOfTck >= 10 ){
        
        serviceChicken = numOfTck / 10;
        result += serviceChicken;
        numOfTck = numOfTck % 10;
        numOfTck += serviceChicken;
        
    }
    
    return result;
}
