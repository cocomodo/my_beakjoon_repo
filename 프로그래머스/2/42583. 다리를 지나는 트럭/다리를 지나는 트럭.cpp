#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

	queue<int> wait; //통행하기를 기다리고 있는 차량들
	queue<int> bridge; // 다리위 차량들의 이동 상태. 빈 공간도 포함
    for( auto t: truck_weights) wait.push(t);
	int total = 0;
	int sec = 0;

	do {
		sec++;

		if (bridge.size() == bridge_length) { //다리 위에 차량이던지, 혹은 0 으로 꽉 차 있는 상태. 즉 맨 앞의 원소가 이제 다리에서 내릴 예정
			total -= bridge.front();
			bridge.pop();
		}

		if (!wait.empty() && (total + wait.front()) <= weight) { //기다리는 차량이 비어있지 않고, 다리위에 있는 총 차량들의 무게와 기다리고 있는 첫번째 차량의 무게를 합친것이 다리의 총 하중보다 작거나 같을때
			total += wait.front();//다리위에 올라갔기 때문에 total 무게에 추가
			bridge.push(wait.front());// 다리 위에 올라갔기 때문에 bridge에 추가
			wait.pop();
		} 
		else bridge.push(0); // 다리 위의 상태에 0 이라는 원소로 공간을 채움. 이 경우 그 위치에 건너는 것이 없는 상태

	} while (total); //total이 0이 될때까지 위의 과정을 지속적으로 수행. total이 0이 되었다는 의미는 모든 차량의 통행이 끝났다는 의미. 

	return sec;
}