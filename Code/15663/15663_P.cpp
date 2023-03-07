#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> v; 
set<vector<int>> s;

int main(){
	int N, M, n;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++){
		scanf("%d", &n);
		v.push_back(n);		
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < (1 << N); i++){
		int cnt = 0;
		for (int j = 0; j < N; j++) if (i & (1 << j)) cnt++;
		if (cnt != M) continue;
		vector<int> tmp;
		for (int j = 0; j < N; j++){
			if (i & (1 << j)) {
				tmp.push_back(v[j]);
			}
		}	
		do {
			if (s.count(tmp)) continue;
			s.insert(tmp);
		}
		while (next_permutation(tmp.begin(), tmp.end()));
	}

	for (vector<int> sv : s) {
		for (int i : sv) printf("%d ", i);
		printf("\n");
	}
}
