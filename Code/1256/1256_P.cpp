#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define INF 1000000000
int N, M, NM, K;
int comb[201][201];
int zPos[200];

void solve(int i){
    //i번째가 a라고 하자.
    if (i == NM) return;
    //printf("comb : %d, K: %d\n", comb[N + M - 1][M], K);
    if (comb[N + M - 1][M] >= K){
        printf("a");
        N--;
        solve(i + 1);
    }
    else {
        printf("z");
        K -= comb[N + M - 1][M];
        M--;
        solve(i + 1);        
    }
}

int main(){
    for (int i = 0; i < 201; i++){
        for (int j = 0; j <= i; j++){
            if (j == 0) comb[i][j] = 1;
            else if (i == j) comb[i][j] = 1;
            else {
                comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
                if (comb[i][j] >= INF) comb[i][j] = INF;
            }
        }
    }

    scanf("%d%d%d", &N, &M, &K);
    NM = N + M;
    if (comb[N + M][N] < K) printf("-1");
    else {
        solve(0);
    }    
}
