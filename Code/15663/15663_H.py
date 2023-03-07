import sys
sys.stdin = open('init.txt', 'r')
#####
from itertools import permutations
n, m = map(int, input().split())
arr = list(map(int, input().split()))
ans = set()
for i in permutations(arr, m):
    if i not in ans:
        ans.add(i)
ans = sorted(ans)
for i in ans:
    print(*i)