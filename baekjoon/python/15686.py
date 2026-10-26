import sys
from itertools import combinations

input = sys.stdin.readline
N, M = map(int, input().split())
mp = [list(map(int, input().split())) for _ in range(N)]
chicken = []
home = []
min_ret = 1e9
for i in range(N):
  for j in range(N):
    if mp[i][j] == 2:
      chicken.append((i, j))
    elif mp[i][j] == 1:
      home.append((i, j))

for c in combinations(chicken, M):
  temp = 0
  for i in home:
    local_result = []
    for j in c:
      local_result.append(abs(j[0] - i[0]) + abs(j[1] - i[1]))
    temp += min(local_result)
  min_ret = min(min_ret, temp)

print(min_ret)
