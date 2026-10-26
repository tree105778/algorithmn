import sys
from itertools import permutations

sys.setrecursionlimit(10**6)
input = sys.stdin.readline
N = int(input())
scv = list(map(int, input().split())) + [0, 0, 0]
dmg = [9, 3, 1]
dp = [[[0 for _ in range(61)] for _ in range(61)] for _ in range(61)]


def dfs(x, y, z):
  if x <= 0 and y <= 0 and z <= 0:
    return 0

  if dp[x][y][z] != 0:
    return dp[x][y][z]

  dp[x][y][z] = 1e9
  for i in permutations(dmg, 3):
    nx = max(x - i[0], 0)
    ny = max(y - i[1], 0)
    nz = max(z - i[2], 0)
    dp[x][y][z] = min(dfs(nx, ny, nz) + 1, dp[x][y][z])
  return dp[x][y][z]


print(dfs(scv[0], scv[1], scv[2]))
