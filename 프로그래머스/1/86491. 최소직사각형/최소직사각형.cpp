#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) { 
    int mxc=0;
    int mxr=0;
    for(auto t: sizes){
        sort(t.begin(),t.end(),greater<int>());
        mxc=max(mxc,t[0]);
        mxr=max(mxr,t[1]);
    }
    return mxc*mxr;
}