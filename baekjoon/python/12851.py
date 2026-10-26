import sys
from collections import deque

N, K = map(int, sys.stdin.readline().split())
queue = deque([N])
dist = [-1] * 100005
cnt = [0] * 100005

dist[N] = 0
cnt[N] = 1

while queue:
  n = queue.popleft()

  for i in [n - 1, n + 1, n * 2]:
    if 0 <= i <= 100000:
      if dist[i] == -1:
        dist[i] = dist[n] + 1
        cnt[i] = cnt[n]
        queue.append(i)
      elif dist[i] == dist[n] + 1:
        cnt[i] += cnt[n]

print(dist[K])
print(cnt[K])
