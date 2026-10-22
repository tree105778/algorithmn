import sys
from collections import deque

dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]


def main():
  queue = deque()
  n, m = map(int, sys.stdin.readline().split())
  visited = [[0] * m for _ in range(n)]
  mp = [list(map(int, sys.stdin.readline().rstrip())) for _ in range(n)]
  queue.append((0, 0))
  visited[0][0] = 1
  while queue:
    y, x = queue.popleft()
    for i in range(4):
      ny = y + dy[i]
      nx = x + dx[i]
      if ny < 0 or ny >= n or nx < 0 or nx >= m:
        continue
      if mp[ny][nx] == 1 and visited[ny][nx] == 0:
        queue.append((ny, nx))
        visited[ny][nx] = visited[y][x] + 1

  print(visited[n - 1][m - 1])


if __name__ == "__main__":
  main()
