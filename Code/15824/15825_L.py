import sys
sys.stdin = open("input.txt", "r")
n = int(sys.stdin.readline())
arr = sorted(list(map(int, sys.stdin.readline().split())))
divisor = int(1e9 + 7)

dic = [1] * n
for i in range(1, n): 
    dic[i] = (dic[i-1] * 2) % divisor

ans = 0
for i in range(n):
    ans += arr[i] * (dic[i] - dic[n - i - 1])
    ans = ans % divisor

print(ans)