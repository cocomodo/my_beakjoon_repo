#include <iostream>

int solution(int num1, int num2) {
    int answer;
    answer = num1 + num2;
    return answer;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    int num1, num2;
    std::cin >> num1 >> num2;
    std::cout << solution(num1, num2);
}