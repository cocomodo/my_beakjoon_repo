#include <bits/stdc++.h>
using namespace std;

int n, m;
deque<pair<int,int>> dq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        
        //이렇게 해야 오름차순으로 정렬되어서 가장 앞쪽에 있는걸 매 인덱스마다 출력하면서 원하는 최솟값들을 나타낼 수 있게 만든다. 
        while(!dq.empty() && dq.back().second>=num)
            dq.pop_back();
        
        dq.push_back({i,num});

        if(dq.front().first<=i-m) //갯수를 유지시키기 위한 코드
            dq.pop_front();
        
        cout<<dq.front().second<<' ';
    }
}
//결국 deque를 이용해서 m개를 넘어가버리게 되면 앞쪽에서 빼버리게 하고, deque 내에서 새롭게 받아들이는 num보다 큰 수는 다 뒤로 다 빼버리게 만들어서 새로운 num이 deque에 담긴 수중에서 가장 큰 수가 되도록 증가하는 수들을 deque에 담게 만든다. 그렇게 해서 가장 작은 수를 매 인덱스마다 front().second 값을 출력해서 나타내는 방식으로 구현. 
