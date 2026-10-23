import sys
from collections import deque
from itertools import combinations

input = sys.stdin.readline

N, M = map(int, input().split())

mp = [list(map(int, input().split())) for _ in range(N)]
virus = [
  (r, c)
  for r, matrix in enumerate(mp)
  for c, val in enumerate(matrix)
  if val == 2
]
zero = [
  (r, c)
  for r, matrix in enumerate(mp)
  for c, val in enumerate(matrix)
  if val == 0
]

dt = [(0, -1), (1, 0), (0, 1), (-1, 0)]
max_ret = 0


def bfs():
  global max_ret
  dq = deque()
  test_mp = [k[:] for k in mp]
  visited = [[False] * M for _ in range(N)]
  for i in virus:
    dq.append(i)

  while dq:
    y, x = dq.popleft()
    for i in range(4):
      ny = y + dt[i][1]
      nx = x + dt[i][0]
      if ny < 0 or ny >= N or nx < 0 or nx >= M:
        continue
      if test_mp[ny][nx] == 0 and not visited[ny][nx]:
        test_mp[ny][nx] = 2
        visited[ny][nx] = True
        dq.append((ny, nx))
  curr = sum(i.count(0) for i in test_mp)
  max_ret = max(curr, max_ret)


def makewall():
  for i in combinations(zero, 3):
    for j in i:
      mp[j[0]][j[1]] = 1
    bfs()
    for j in i:
      mp[j[0]][j[1]] = 0


makewall()
print(max_ret)
