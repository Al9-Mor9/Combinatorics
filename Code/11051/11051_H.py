import sys
sys.stdin = open('init.txt', 'r')
#####
from math import factorial
n, k = map(int, input().split())
# nCk = n!/(k!(n-k)!)
result = factorial(n) // (factorial(k) * factorial(n - k))
print(result % 10007)
