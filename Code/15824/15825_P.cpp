#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> scoville;
int p;
long long tmp, ans;
long long power[300001];

int main(){
    int N, p;
    power[0] = 1; 
    scanf("%d", &N);
    scoville.resize(N+1);
    for (int i = 1; i <= N; i++){
        power[i] = (power[i-1] * 2) % 1000000007;
    }

    for (int i = 1; i <= N; i++){
        scanf("%lld", &scoville[i]);
    }
    sort(scoville.begin(), scoville.end());
    for (int i = 1; i <= N; i++){
        scoville[i] += scoville[i-1];
    }
    
    for (int i = 1; i <= N; i++){
        tmp = (scoville[N] - scoville[N - i] - scoville[i]) % 1000000007;
        tmp *= power[i-1];
        ans += tmp;
        ans %= 1000000007;
    }

    printf("%lld", ans);
}
