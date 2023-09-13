#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array) {
    sort(array.begin(),array.end());
    int c= array.size()/2;
    return array[c];
}