import sys

sys.setrecursionlimit(10**6)
N = int(sys.stdin.readline())
mp = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
limit = max(x for row in mp for x in row)
result = []
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]


def dfs(y, x):
  visited[y][x] = 1

  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]

    if (
      0 <= nx < N
      and 0 <= ny < N
      and visited[ny][nx] == 0
      and mp[ny][nx] > height
    ):
      dfs(ny, nx)


for height in range(limit):
  ret = 0
  visited = [[0] * N for _ in range(N)]
  for i in range(N):
    for j in range(N):
      if not visited[i][j] and mp[i][j] > height:
        dfs(i, j)
        ret += 1
  result.append(ret)

print(max(result))
