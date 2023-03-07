#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	int **combi = new int*[N + 1];
	for (int i = 0; i < N + 1; i++) {
		combi[i] = new int[N + 1];
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 1) combi[i][j] = i;
			else if (j == i) combi[i][j] = 1;
			else combi[i][j] = (combi[i - 1][j - 1] % 10007 + combi[i - 1][j] % 10007)%10007;
		}
	}

	printf("%d", combi[N][K]);
}
