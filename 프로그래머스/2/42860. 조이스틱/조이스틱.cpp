#include <bits/stdc++.h>

using namespace std;

int solution(string name){
    int answer=0;
    int n = name.length();
    int turn = n-1;
    for(int i=0; i<n; i++){
        if(name[i]-'A'<14) answer+=name[i]-'A';
        else answer+='Z'- name[i]+1;
        
        int ind=i+1;
        while(ind < n && name[ind] == 'A') ind++;
        //이때에 a= i, b= n-ind;
        // 첫번재 자리부터, a 이동, 되돌아오기 a 이동, 뒤로 꺽어서 b 이동
        // 첫번째 자리부터, 뒤로 꺽어서 b 이동, 되돌아오기 b 이동, a 이동 순으로 생각했을때
        // a + a + b 와 b + b +a 를 비교해서 더 작은 값을 갖는것이 가장 작은 이동횟수가 된다. 
        turn = min(turn , i+(n-ind) + min(i, (n-ind)));// 이해하기 쉽게 (n-ind)에 괄호를 침
        //turn = min(turn, i+ n-ind + min(i, n-ind)); 로 작성해도 무방함.
    }
    answer+= turn; 
    return answer;
}