import sys

sys.setrecursionlimit(10**6)
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]
result = []


def dfs(y, x):
  visited[y][x] = 1
  for i in range(4):
    ny = y + dy[i]
    nx = x + dx[i]
    if ny < 0 or ny >= N or nx < 0 or nx >= M:
      continue
    if mp[ny][nx] == 1 and visited[ny][nx] == 0:
      dfs(ny, nx)


T = int(sys.stdin.readline())
while T:
  ret = 0
  N, M, K = map(int, sys.stdin.readline().split())
  mp = [[0] * M for _ in range(N)]
  visited = [[0] * M for _ in range(N)]
  for _ in range(K):
    a, b = map(int, sys.stdin.readline().split())
    mp[a][b] = 1
  for i in range(N):
    for j in range(M):
      if visited[i][j] == 0 and mp[i][j]:
        dfs(i, j)
        ret += 1
  T -= 1
  result.append(str(ret))

print("\n".join(result))
