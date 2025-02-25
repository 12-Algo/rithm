# 시간 내 풀이 못함

import sys
sys.setrecursionlimit(10 ** 6)

n = int(input())
wine = [int(input()) for _ in range(n)]
memo = [-1] * n
