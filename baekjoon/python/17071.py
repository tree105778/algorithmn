import sys
from collections import deque

N, K = map(int, sys.stdin.readline().split())
queue = deque([(N, 0)])
dist = [-1] * 500005
dist[N] = 0

while queue:
  n, a = queue.popleft()
  target = sum([i for i in range(a + 1)]) + K
  # print(target)
  if n == target:
    print(dist[target])
    break
  for i in [n - 1, n + 1, n * 2]:
    if 0 <= i <= 500000 and dist[i] == -1:
      dist[i] = dist[n] + 1
      queue.append((i, a + 1))

# print(dist[K])
