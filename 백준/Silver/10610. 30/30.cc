#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> nums;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    for(char c:s)
     nums.push_back(c-'0');
    sort(nums.begin(),nums.end(),greater<int>());
    int sum=accumulate(nums.begin(),nums.end(),0);
    if(sum%3==0&&nums.back()==0)
        for(int c: nums)
          cout<<c;
    else 
      cout<<-1;
    
}