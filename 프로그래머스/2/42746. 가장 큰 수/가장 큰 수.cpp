#include <bits/stdc++.h>

using namespace std;

bool cmp(string &a, string &b) { 
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> tmp;
    
	for (auto t : numbers) tmp.push_back(to_string(t));
	sort(tmp.begin(), tmp.end(), cmp);
    
	for (auto t: tmp) answer += t; 
	if (answer[0] == '0') return "0";
	return answer;
}