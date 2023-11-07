#include <bits/stdc++.h>

using namespace std;

map<int, bool> M;

bool isPrime(string num){
    int n = stoi(num);
    
    if(M[n]) return false; 
    M[n] = true;
    if(n == 1 || n == 0) return false;
    if(n == 2) return true;
    
    for(int i=2; i<=sqrt(n); i++){
        if(n % i == 0){
            M[n] = false;
            return false;
        }              
    }
    M[n] = true;
    return true;
}

int solution(string numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end());
    do{
        for(int i=1; i<=numbers.size(); i++){
            string num = numbers.substr(0, i);         
            if(isPrime(num)) answer++;
        }
    }while(next_permutation(numbers.begin(), numbers.end())); //next_permutation을 통해서 다음 순열로 테스트
    
    return answer;
}