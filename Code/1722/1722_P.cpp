#include <iostream>
using namespace std;

int N, problemNum;
long long factorial[21];
int perm[20];
int ansPerm[20];
long long k;

long long getPermNum(){
    bool selected[21] = {false, };
    long long ans = 0;
    for (int i = 0; i < N; i++){
        selected[perm[i]] = true;
        long long cnt = 0;
        for (int j = 1; j < perm[i]; j++){
            if (!selected[j]) cnt++;
        }        
        ans += (cnt) * factorial[N - 1 -i];       
    }
    return ans + 1;
}

void getPerm(long long k, int i, bool selected[]){
    if (i == N) return;
    long long fact = factorial[N - 1 - i];
    long long a = k / fact;
    int cnt = 0;
    int sel = 0;
    for (int i = 1; i <= N; i++){
        if (cnt == a) sel = i;
        if (!selected[i]) cnt++;
    }
    selected[sel] = true;
    ansPerm[i] = sel;
    getPerm(k - (fact * a), i + 1, selected);
}


int main(){
    factorial[0] = 1;
    for (int i = 1; i <= 20; i++) factorial[i] = factorial[i - 1] * i;    
    scanf("%d", &N);
    scanf("%d", &problemNum);
    if (problemNum == 1){
        scanf("%lld", &k);
        bool selected[21] = {false, };
        getPerm(k - 1   , 0, selected);
        for (int i = 0; i < N; i++){
            printf("%d ", ansPerm[i]);
        }
    }
    else {
        for (int i = 0; i < N; i++) scanf("%d", &perm[i]);
        printf("%lld", getPermNum());
    }
}
