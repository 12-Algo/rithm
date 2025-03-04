# 시간 내 풀이 못함

import sys
sys.setrecursionlimit(10 ** 6)

def dfs(before, last):
    # 종료 조건
    if last >= N - 2:
        return 0
    # 이전에 연속해서 선택했을 경우
    if last - before == 1:
        return dfs(last, last + 2) + wines[last + 2]
    else:
        a = dfs(last, last + 1) + wines[last + 1]
        b = dfs(last, last + 2) + wines[last + 2]
        return max(a, b)

# 기본 세팅
N = int(input())
wines = [int(input()) for _ in range(N)]
memo = [-1] * n
print(max(dfs(0, 1) + wines[0] + wines[1], dfs(0,2) + wines[0] + wines[2], dfs(1,2) + wines[1] + wines[2]))

# 풀고 싶었던 방식
# import sys
# sys.setrecursionlimit(10 ** 6)

# def dfs(i):
#     if memo[i] != -1:
#         return memo[i]
    
#     if i == 0:
#         return wine[0]
#     elif i == 1:
#         return wine[0] + wine[1]
#     elif i == 2:
#         return max(wine[0] + wine[2], wine[1] + wine[2], wine[0] + wine[1])

#     memo[i] = max(dfs(i - 1), dfs(i - 2) + wine[i], dfs(i - 3) + wine[i - 1] + wine[i])
#     return memo[i]

# n = int(input())
# wine = [int(input()) for _ in range(n)]

# memo = [-1] * n

# print(dfs(n - 1))