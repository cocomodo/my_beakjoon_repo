#include <string>
#include <vector>

using namespace std;

int comb[35][35];

int solution(int n, int r) {
    int answer = 0;
    for(int i=1; i<=30;i++){
        comb[i][0]=comb[i][i]=1;
        for(int j=1;j<i;j++){
            comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
        }
    }
    answer=comb[n][r];
    return answer;
}