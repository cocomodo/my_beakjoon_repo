//1 2 3 3 4
#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    int sum=0;
    for(int i=0; i<n; i++){
        int midsum=0;
        for(int j=0; j<=i;j++){
            midsum+=a[j];
        }
        sum+=midsum;
    }
    cout<<sum;
}