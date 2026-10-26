import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)
N, M = map(int, input().split())
mp = [list(map(str, input().rstrip())) for _ in range(N)]
visited = [[False] * M for _ in range(N)]
ret = 0
d = [(-1, 0), (0, 1), (1, 0), (0, -1)]

queue = [mp[0][0]]

visited[0][0] = True


def dfs(y, x):
  global ret
  # print(f"y = {y}, x = {x}, queue={queue}")
  for i in range(4):
    ny = y + d[i][0]
    nx = x + d[i][1]

    if ny < 0 or ny >= N or nx < 0 or nx >= M:
      continue

    if not visited[ny][nx] and mp[ny][nx] not in queue:
      queue.append(mp[ny][nx])
      visited[ny][nx] = True
      dfs(ny, nx)
      visited[ny][nx] = False
      queue.pop()
  ret = max(ret, len(queue))


dfs(0, 0)
print(ret)
